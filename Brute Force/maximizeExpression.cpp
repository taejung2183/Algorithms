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
	int ans;
	int ln = stoi(leftNum), rn = stoi(rightNum);

	if (oper == '*') ans = ln * rn;
	else if (oper == '+') ans = ln + rn;
	// oper == '-'
	else ans = ln - rn;

	return to_string(ans);
}

long long solveExpression(string expression, string priority) {
	long long answer = 0;

	cout << "Priority: " << priority << endl << endl;
	for (int i = 0; i < priority.length(); ++i) {
		char oper = priority[i];

		// Resolve all the "oper" operators in the expression.
		int leftNumIdx, rightNumIdx, operIdx = 1;
		string leftNum = "", rightNum = "";
		while (operIdx < expression.length()) {
			if (expression.at(operIdx) == oper) {

				////----- RIGHT SIDE ----- ////
				rightNumIdx = operIdx + 1;
				while (rightNumIdx < expression.length()) {
					// If there's a '-' at the front, add it to the string.
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
				 	// Need to insert at the front. (Since you're decreasing leftNumIdx.)
					if ('0' <= expression.at(leftNumIdx) && expression.at(leftNumIdx) <= '9') 
						leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
					// If the expression[leftNumIdx] is '-', check if there's another operator at the front.
					else {
						if (expression.at(leftNumIdx) != '-') break;
						// If there's more space for another operator and if it's actually an operator.
						if (leftNumIdx == 0 || (1 < leftNumIdx && 
								(expression.at(leftNumIdx - 1) < '0' || '9' < expression.at(leftNumIdx - 1)))) {
							// Insert '-' to the leftNum string.
							leftNum.insert(leftNum.begin(), expression[leftNumIdx]);
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
				if (ans[0] == '-') {
					if (1 < leftNumIdx && expression[leftNumIdx - 1] == '+') {
						expression.erase(leftNumIdx - 1, 1);
						leftNumIdx -= 2;
					}
				}

				// Adjusting operIdx.
				//if (leftNumIdx == 0) leftNumIdx += 1;
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
	long long answer = 0;
	string operators = "";
	vector<long long> candidates;
	
	// Check if each operator is in the expression.
	for (const auto& e: expression) if (e == '*') { operators += "*"; break; }
	for (const auto& e: expression) if (e == '+') { operators += "+"; break; }
	for (const auto& e: expression) if (e == '-') { operators += "-"; break; }
	cout << operators.length() << " operators in the expression." << endl;

	// Make an operator priority with permutation.
	do { 
		candidates.push_back(solveExpression(expression, operators));
	} while (next_permutation(operators.begin(), operators.end()));

	for (const auto& e: candidates) cout << e << " ";
	cout << endl;

	// Choose the biggest calculation.
	answer = candidates[0];
	for (const auto& e: candidates) answer = max(answer, e);

	cout << "ANSWER: " << answer << endl;
	return answer;
}

int main(int argc, char* argv[]) {
	solution(argv[1]);
	//cout << solution("100-200*300-500+20") << endl;
	//cout << solution("50*6-3*2") << endl;
	return 0;
}
