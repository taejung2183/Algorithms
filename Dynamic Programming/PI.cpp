#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cache[10000];
vector<int> numbers;

int calculateLevel(vector<int>& piece) {
	int first = piece[0], len = piece.size();

	// Level 1
	bool flag = true;
	for (int i = 1; i < len; ++i) 
		if (piece[i] != first) flag = false;
	if (flag) return 1;
	
	// Level 2
	flag = true;
	if (piece[0] + 1 == piece[1]) {
		for (int i = 1; i < len - 1; ++i) 
			if (piece[i] + 1 != piece[i + 1]) flag = false;
	}
	else if(piece[0] - 1 == piece[1]) {
		for (int i = 1; i < len - 1; ++i) 
			if (piece[i] - 1 != piece[i + 1]) flag = false;
	}
	if (flag) return 2;

	// Level 4
	flag = true;
	int second = piece[1];
	for (int i = 3; i < len; ++i) {
		if (i % 2 == 1 && piece[i] != first ||
				i % 2 == 0 && piece[i] != second)
			flag = false;
	}
	if (flag) return 4;

	// Level 5
	flag = true;
	int diff = first - second;
	for (int i = 1; i < len - 1; ++i) 
		if (piece[i] - piece[i + 1] != diff) flag = false;
	if (flag) return 5;

	return 10;
}

int PI(int idx) {
	int& ret = cache[idx];
	if (ret != -1) return ret;

	// Maximum level.
	ret = 34000;
	vector<int> piece;
	int level;
	// Pick 3 to five numbers.
	for (int step = 3; step <= 5; ++step) {
		// Un-divisible.
		if (numbers.size() < idx + step) {
			ret = 34000; break;
		}
		// Slice the numbers until before the next idx.
		for (int i = idx; i < idx + step; ++i) 
			piece.push_back(numbers[i]);
		level = calculateLevel(piece);
		ret = min(ret, PI(idx + step) + level);
		piece.clear();
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
