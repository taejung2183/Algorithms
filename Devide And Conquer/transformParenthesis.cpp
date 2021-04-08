#include <iostream>
#include <string>
using namespace std;

bool isCorrect(string p) {
	int correct = 0;
	for (const auto& e: p) {
		e == '(' ? correct += 1 : correct -= 1;
		if (correct < 0) return false;
	}
	return true;
}

bool isBalanced(string p) {
	int balance = 0;
	for (const auto& e: p) 
		e == '(' ? balance += 1 : balance -=1;
	return balance == 0 ? true : false;
}

void reverseParenthesis(string& p) {
	for (auto& e: p) e = (e == '(') ? ')' : '(';
}

string solution(string p) {
    string answer = "";
	string u = "", v = "";

	// 1. If p is empty, return p.
	if (p.empty() == true) return p;

	// 2. Separate p to u and v.
	// Generate u.
	u.append(1, p.at(0));
	int i = 1;
	// Fill up u until it becomes balanced string.
	while (i < p.length() && isBalanced(u) == false) {
		u.append(1, p.at(i));
		i += 1; 
	}
	// Generate v.
	v = p.substr(i);

	// 3. If u is correct, get into recursion with v.
	if (isCorrect(u)) return u + solution(v);

	// 4. u isn't correct.
	answer.append(1, '(').append(solution(v)).append(1, ')');
	u.erase(u.begin());
	u.erase(u.end() - 1);
	reverseParenthesis(u);
	answer.append(u);

    return answer;
}

int main(int argc, char* argv[]) {
	cout << solution(argv[1]) << endl;
	return 0;
}
