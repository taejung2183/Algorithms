#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long a, long long b, char oper) {
	long long ret;
	if (oper == '*') ret = a * b;
	else if (oper == '+') ret = a + b;
	else ret = a - b;
	return ret;
}

long long maximize(string prior, string expression) {
	vector<long long> nums;
	vector<char> opers;

	for (int i = 0; i < expression.size(); ++i) {
		char e = expression[i];
		if (e == '*' || e == '+' || e == '-') {
			nums.push_back(stoi(expression.substr(0, i)));
			opers.push_back(e);
			expression = expression.substr(i + 1);
			i = 0;
		}
	}
	nums.push_back(stoi(expression));

	for (int i = 0; i < prior.size(); ++i) {
		auto opersIt = find(opers.begin(), opers.end(), prior[i]);
		if (opersIt != opers.end()) {
			auto numsIt = nums.begin() + (opersIt - opers.begin());
			int idx = numsIt - nums.begin();
			auto it = nums.insert(numsIt, calculate(nums[idx], nums[idx + 1], prior[i]));
			nums.erase(++it); nums.erase(it); opers.erase(opersIt);
			--i; // Find once more.
		}
	}

	return abs(nums[0]);
}

long long solution(string expression) {
    long long answer = 0;
	const string prior[6] = {"+-*","+*-","-+*","-*+","*+-","*-+"};

	for (int i = 0; i < 6; ++i) 
		answer = max(answer, maximize(prior[i], expression));

    return answer;
}

int main() {
	//string e = "100-200*300-500+20";
	string e = "50*6-3*2";
	cout << solution(e) << '\n';
	return 0;
}

// g++ -std=c++11 -Wall maximizeExpression.cpp -o maximizeExpression
