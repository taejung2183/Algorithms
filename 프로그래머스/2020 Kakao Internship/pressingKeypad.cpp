#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int keyPos[13][3] = {
	{-1,-1}, // Dummy for matching up index with actual number.
	{0,0}, // 1
	{0,1},
	{0,2},
	{1,0}, // 4
	{1,1},
	{1,2},
	{2,0}, // 7
	{2,1},
	{2,2}, // 9
	{3,0}, // *
	{3,1}, // 0
	{3,2}, // # 
};

int calDist(int l, int r, int t) {
	int ret;
	int l1 = keyPos[l][0], l2 = keyPos[l][1];
	int r1 = keyPos[r][0], r2 = keyPos[r][1];
	int t1 = keyPos[t][0], t2 = keyPos[t][1];
	int lt = abs(l1 - t1) + abs(l2 - t2);
	int rt = abs(r1 - t1) + abs(r2 - t2);
	
	if (lt > rt) ret = 1;
	else if (lt < rt) ret = -1;
	else ret = 0;
	
	return ret;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
	int l = 10; int r = 12;
	int h = hand.compare("left");

	for (int i = 0; i < numbers.size(); ++i) {
		int n = numbers[i];
		if (n == 1 || n == 4 || n == 7) {
			answer += "L";
			l = n;
		}
		else if (n == 3 || n == 6 || n == 9) {
			answer += "R";
			r = n;
		}
		else {
			int dist;
			if (n == 0) n = 11;
			if ((dist = calDist(l, r, n)) == 0) {
				// Same distance.
				if (!h) { answer += "L"; l = n; }
				else { answer += "R"; r = n; }
			} 
			else {
				// -1: Press with left, 1: Right.
				if (dist == -1) { answer += "L"; l = n; }
				else { answer += "R"; r = n; }
			}
		}
	}

    return answer;
}

int main() {
	vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	string hand = "right";

	cout << solution(numbers, hand) << '\n';

	return 0;
}

// g++ -std=c++11 -Wall pressingKeypad.cpp -o pressingKeypad
