#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long calculate(long long ln, long long rn, char oper) {
	long long ret;

	cout << ln << oper << rn << endl;

	if (oper == '*') ret = ln * rn;
	else if (oper == '+') ret = ln + rn;
	else if (oper == '-') ret= ln - rn;

	return ret;
}

long long solveExpression(vector<long long> numbers, vector<char> operators, string priority) {
	for (int priorityIdx = 0; priorityIdx < priority.length(); ++priorityIdx) {
		// Search for the prior operator.
		for (int operIdx = 0; operIdx < operators.size(); ++operIdx) {
			if (operators.at(operIdx) == priority.at(priorityIdx)) {
				// Calculate the sub expression and extract the operands and operator.
				long long ans = calculate(numbers.at(operIdx), numbers.at(operIdx + 1), operators.at(operIdx));
				numbers.erase(numbers.begin() + operIdx);
				numbers.erase(numbers.begin() + operIdx);
				operators.erase(operators.begin() + operIdx);

				numbers.insert(numbers.begin() + operIdx, ans);
				operIdx -= 1;
			}
		}
	}
	return numbers.at(0);
}

long long solution(string expression) {
	long long answer = 0;
	vector<char> operators;
	vector<long long> numbers;
	string number = "";
	string priority = "*+-";

	// Seperate numbers and operators in each vector.
	for (int i = 0; i < expression.length(); ++i) {
		// expression[i] is a number.
		if ('0' <= expression.at(i) && expression.at(i) <= '9') {
			number += expression.at(i);
		} else { 
			// expression[i] is an operator.
			numbers.push_back(stoi(number));
			operators.push_back(expression.at(i));
			number = "";
		}
	}
	// Add the last number of the expression.
	numbers.push_back(stoi(number));

	// Solve the expression with all the possible priorities.
	do {
		// Choose the maximum result.
		answer = max(answer, abs(solveExpression(numbers, operators, priority)));
	} while (next_permutation(priority.begin(), priority.end()));

	return answer;
}

int main(int argc, char* argv[]) {
	cout << solution(argv[1]) << endl;
	return 0;
}
