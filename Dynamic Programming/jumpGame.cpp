#include <iostream>
#include <vector>
using namespace std;

// Initial state: -1, NO: 0, YES: 1
int cache[100][100];

int jumpGame(vector<vector<int>> board, int y, int x) {
	int goal = board.size() - 1;
	// Out of range.
	if (goal < y || goal < x) return 0;
	// Arrived!
	if (goal == y && goal == x) return 1;

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = jumpGame(board, y + board[y][x], x) || jumpGame(board, y, x + board[y][x]);
}

int main() {
	int C; cin >> C;
	vector<vector<int>> board;
	vector<int> answers;

	while (C-- > 0) {
		int n, cin >> n;

		for (int i = 0; i < n; ++i) {
			vector<int> row;
			for (int j = 0; j < n; ++j) {
				int e; cin >> e;
				row.push_back(e);
			}
			board.push_back(row);
			row.clear();
		}

		memset(cache, -1, sizeof(cache));
		answers.push_back(jumpGame(board,0,0));
		board.clear();
	}

	for (const auto& e: answers) cout << e << " ";
	cout << endl;

	return 0;
}
