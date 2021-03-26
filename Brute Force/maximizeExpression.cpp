#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*string getNumberNextToOper(int operIdx, const string& expression, string dir) {
	string num = "";
	string::iterator itr;

	if (dir == "right") itr = num.end();
	else itr = num.begin();
}*/

string calculate(string leftNum, string rightNum, char oper) {
	long long ret, ln = stoi(leftNum), rn = stoi(rightNum);

	if (oper == '*') ret = ln * rn;
	else if (oper == '+') ret = ln + rn;
	else if (oper == '-') ret= ln - rn;

	return to_string(ret);
}

long long solveExpression(string expression, string priority) {
	long long answer = 0;

	cout << "Priority: " << priority << endl << endl;
	for (int i = 0; i < priority.length(); ++i) {
		char oper = priority[i];

		// Resolve all the "oper" operators in the expression.
		int leftNumIdx, rightNumIdx, operIdx = 1;
		string leftNum = "", rightNum = "";
		while (0 <= operIdx && operIdx < expression.length()) {
			if (expression.at(operIdx) == oper) {

				////----- RIGHT SIDE ----- ////
				rightNumIdx = operIdx + 1;
				while (rightNumIdx < expression.length()) {
					// If there's '-' at the front, add it to the string.
					if (rightNumIdx == operIdx + 1 && expression.at(rightNumIdx) == '-') {
							rightNum += expression[rightNumIdx];
					} else {
						if ('0' <= expression.at(rightNumIdx) && expression.at(rightNumIdx) <= '9') 
							rightNum += expression[rightNumIdx];
						else break;
					}
					rightNumIdx += 1;
				}
				
				////----- LEFT SIDE ----- ////
				leftNumIdx = operIdx - 1;
				while (0 <= leftNumIdx) {
					if ('0' <= expression.at(leftNumIdx) && expression.at(leftNumIdx) <= '9') 
						leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
					// If the expression[leftNumIdx] is '-', check if there's more operator at the front.
					else {
						if (expression.at(leftNumIdx) == '-') {
							// If there's more space for another operator and if it's actually an operator,
							// insert '-' to the string because it's a sign of the number. (Not an operator.)
							if (leftNumIdx == 0) leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
							else if (expression.at(leftNumIdx - 1) < '0' || '9' < expression.at(leftNumIdx - 1))
								leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
							else break;

							/*
							if (leftNumIdx == 0 || (1 < leftNumIdx && 
										(expression.at(leftNumIdx - 1) < '0' || '9' < expression.at(leftNumIdx - 1)))) {
								leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
							} else break;
							*/
						} else break;
					}
					leftNumIdx -= 1;
				}

				////----- CALCULATION -----////
				cout << "expression: " << expression << endl;
				cout << "current calculation: " << leftNum << oper << rightNum << endl << endl;
				string ans = calculate(leftNum, rightNum, oper);

				// Replace the calculated sub-expression.
				leftNumIdx += 1;
				expression.replace(leftNumIdx, rightNumIdx - leftNumIdx, ans);
				
				// '+-'  ->  '-'
				// Does it matter? Not sure.
				/*if (ans[0] == '-') {
					if (1 < leftNumIdx && expression[leftNumIdx - 1] == '+') {
						expression.erase(leftNumIdx - 1, 1);
						leftNumIdx -= 2;
					}
				}*/

				operIdx = leftNumIdx;
				leftNum = ""; rightNum = "";
			}
			operIdx += 1;
		}

	}

	answer = abs(stoi(expression));
	cout << answer << endl;
	return answer;
}

long long solution(string expression) {
	long long answer = 0,ret = 0;
	string operators = "*+-";
	
	// Make an operator priority with permutation.
	do { 
		ret = solveExpression(expression, operators);
		answer = max(answer, ret);
	} while (next_permutation(operators.begin(), operators.end()));

	cout << "ANSWER: " << answer << endl;
	return answer;
}

int main(int argc, char* argv[]) {
	solution(argv[1]);
	//cout << solution("100-200*300-500+20") << endl;
	//cout << solution("50*6-3*2") << endl;
	return 0;
}
