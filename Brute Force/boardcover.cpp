#include <iostream>
#include <vector>
using namespace std;

// L block 
/*
#   ##  ##   #
##  #    #  ##
*/
const int LBlock[4][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
int H, W;

int boardcover(vector<vector<char>>& board) {
	// Base case: If all the board is covered, return 1.
	// Find the blank at the very upper left in the board.
	int firstY = -1, firstX = -1;
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (board[y][x] == '.') {
				firstY = y;
				firstX = x;
				break;
			}
		}
		if (firstY != -1) break;
	}
	if (firstY == -1) return 1;

	int ret = 0;

	// Task piece: Cover the blank at the very upper left with one of the L block.
	for (int i = 0; i < 4; ++i) {
		bool isCoverable = true;
		int y[3], x[3];
		for (int j = 0; j < 3; ++j) {
			// (y[j], x[j]): coordinate for L blocks.
			y[j] = firstY + LBlock[i][j][0];
			x[j] = firstX + LBlock[i][j][1];
			// if (y[j], x[j]) crosses the boundary of the board or it is already '#', you can't cover.
			if (y[j] < 0 || H <= y[j] || x[j] < 0 || W <= x[j]) 
				isCoverable = false;
			else if (board[y[j]][x[j]] == '#') 
				isCoverable = false;
		}	

		if (isCoverable == false) continue;
		for (int j = 0; j < 3; ++j) 
			board[y[j]][x[j]] = '#';
		ret += boardcover(board);
		for (int j = 0; j < 3; ++j) 
			board[y[j]][x[j]] = '.';
	}

	return ret;
}

int main() {
	int C; cin >> C;
	vector<vector<char>> board;
	vector<int> answers;

	while (C-- > 0) {
		cin >> H >> W;

		vector<char> row;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				char c; cin >> c;
				row.push_back(c);
			}
			board.push_back(row);
			row.clear();
		}
			
		answers.push_back(boardcover(board));	
		board.clear();
	}

	for (auto e: answers)
		cout << e << " ";
	cout << endl;

	return 0;
}
