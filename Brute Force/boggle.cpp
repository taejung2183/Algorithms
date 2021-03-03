// Boggle game
// 알파벳이 나열된 격자와 특정 단어, 격자에서 단어 첫 글자의 위치가
// 주어지면 해당 위치로부터 양 옆, 위, 아래 대각선 방향으로 인접한
// 칸의 글자를 연결해 단어를 완성할 수 있는지 참, 거짓으로 알려준다.

#include <iostream>
#include <vector>
#include <string> 
#define BOARD_WIDTH 5
#define BOARD_HEIGHT 5
using namespace std;

// 5 x 5 cross boards
/*
vector<vector<char>> board = {
	{'u', 'r', 'l', 'p', 'm'},
	{'x', 'p', 'r', 'e', 't'},
	{'g', 'i', 'a', 'e', 't'},
	{'x', 't', 'n', 'z', 'y'},
	{'x', 'o', 'q', 'r', 's'}
};
*/
vector<vector<char>> board = {
	{'n', 'n', 'n', 'n', 's'},
	{'n', 'e', 'e', 'e', 'n'},
	{'n', 'e', 'y', 'e', 'n'},
	{'n', 'e', 'e', 'e', 'n'},
	{'n', 'n', 'n', 'n', 'n'}
};

// Relative position of adjacent 8 cells.
const int directions[8][2] = {
	{-1, -1}, {-1, 0}, {-1, 1},	{0, -1},
	{0, 1},	{1, -1}, {1, 0}, {1, 1}
};

// Task piece -> Matching letter.
// If it matches, recursive call for the word without the first letter.
bool boggle(string word, int yPos, int xPos) {
	// Check for erroneous input.	
	if (yPos < 0 || BOARD_HEIGHT <= yPos || xPos < 0 || BOARD_WIDTH <= xPos) 
		return false;
	if (board[yPos][xPos] != word[0]) return false;
	if (word.length() == 1) return true;

	for (int next = 0; next < 8; ++next) {
		int nextY = yPos + directions[next][0];
		int nextX = xPos + directions[next][1];

		if (boggle(word.substr(1), nextY, nextX) == true) return true;
	}
	return false;
}

int main() {
	string word = "yes";

	// 'y' is at (2, 2) in the board.
	if (boggle(word, 2, 2)) {
		cout << "Success";
	} else {
		cout << "Failure";
	} 
	cout << endl;

	return 0;
}
