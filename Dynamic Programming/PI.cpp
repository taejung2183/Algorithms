#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cache[10000];
vector<int> numbers;

int calculateLevel(vector<int>& piece) {
	int first = piece[0], len = piece.size();
	int second = piece[1];

	// Level 1 : All same.
	bool isCorrect = true;
	for (int i = 1; i < len; ++i) 
		if (piece[i] != first) isCorrect = false;
	if (isCorrect) return 1;
	
	// Level 2 : Increase or decrease by 1.
	isCorrect = true;
	if (first + 1 == second) {
		for (int i = 1; i < len - 1; ++i) 
			if (piece[i] + 1 != piece[i + 1]) isCorrect = false;
	}
	else if(first - 1 == second) {
		for (int i = 1; i < len - 1; ++i) 
			if (piece[i] - 1 != piece[i + 1]) isCorrect = false;
	}
	else isCorrect = false;
	if (isCorrect) return 2;

	// Level 4 : Two numbers are repeating.
	isCorrect = true;
	for (int i = 2; i < len; ++i) {
		if (i % 2 == 1 && piece[i] != first ||
				i % 2 == 0 && piece[i] != second)
			isCorrect = false;
	}
	if (isCorrect) return 4;

	// Level 5 : Isometric sequence.
	isCorrect = true;
	int diff = first - second;
	for (int i = 1; i < len - 1; ++i) 
		if (piece[i] - piece[i + 1] != diff) isCorrect = false;
	if (isCorrect) return 5;

	return 10;
}

int PI(int idx) {
	int& ret = cache[idx];
	if (ret != -1) return ret;

	if (idx == numbers.size()) return ret;

	// Maximum level.
	ret = 34000;
	vector<int> piece;
	int level;
	// Pick 3 to five numbers.
	for (int step = 3; step <= 5; ++step) {
		// Got to the end.
		if (idx == numbers.size()) {
			ret = 0; break;
		}
		// Exceed the length of numbers.
		else if (numbers.size() < idx + step) {
			ret = 34000; break;
		}
		// Get into recursion.
		else {
			for (int i = idx; i < idx + step; ++i) 
				piece.push_back(numbers[i]);
			level = calculateLevel(piece);
			ret = min(ret, PI(idx + step) + level);
			piece.clear();
		}
	}
	return ret;
}

int main() {
	int C; cin >> C;
	vector<int> answers;
	string str;
	 
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));

		cin >> str;
		for (int i = 0; i < str.size(); ++i) 
			numbers.push_back(str[i]-'0');
		
		answers.push_back(PI(0));
		numbers.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}
