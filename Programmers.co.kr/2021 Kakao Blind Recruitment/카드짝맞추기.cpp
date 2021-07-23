#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;
const int INF = 987654321;

/*
How to solve? 

Try out all the  possible sequences with cards
since there's at most 6 cards.

In the worst case, if there are all 6 cards in the board
you only need to check 6! numbers of sequences.
*/

vector<vector<int>> b;
//		{1,0,0,3},
//		{2,0,0,0},
//		{0,0,0,2},
//		{3,0,1,0}
int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
int calDist(int r, int c, pair<int,int> target) {
	// BFS to calculate the minimum key pressing to the target
	queue<pair<pair<int,int>,int>> q;
	int tr = target.first;
	int tc = target.second;

	q.push({{r, c}, 0});
	int minCnt = INF;
	while (!q.empty()) {
		pair<pair<int,int>,int> cur = q.front();
		q.pop();
		int cr = cur.first.first;
		int cc = cur.first.second;
		int cnt = cur.second;
		cout << "cr:" << cr << ", cc:" << cc << ", cnt:" << cnt << '\n';

		// Arrived. Check if you pressed less
		if (cr == tr && cc == tc) 
			minCnt = min(minCnt, cur.second);

		// Normal move
		for (int i = 0; i < 4; ++i) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			// Range check
			if (nr < 0 || nc < 0 || nr >= b.size() || nc >= b.size()) continue;

//			cout << "Normal move pushing:(" << nr << ", " << nc << ")" << '\n';
			q.push({{nr, nc}, cnt + 1});
		}

		// Ctrl move
		for (int i = 0; i < 4; ++i) {
			int dirR = cr;
			int dirC = cc;
			int nr = dirR + dr[i];
			int nc = dirC + dc[i];

			// Range check 
			if (nr < 0 || nc < 0 || nr >= b.size() || nc >= b.size()) continue;
			
			// Repeat if you're standing on zero
			while (b[nr][nc] == 0) {
				dirR += dr[i];
				dirC += dc[i];
				nr = cr + dirR;
				nc = cc + dirC;
				if (nr < 0 || nc < 0 || nr >= b.size() || nc >= b.size()) {
					nr -= dr[i];
					nc -= dc[i];
					break;
				}
			}
//			cout << "Ctrl move pushing:(" << nr << ", " << nc << ")" << '\n';
			q.push({{nr, nc}, cnt + 1});
		}
	}
	return minCnt;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;
	set<int> s;
	vector<int> cardSeq; // Hold sequences of cards
	b = vector<vector<int>>(board.begin(), board.end());

	// Check the kind of card in the board
	for (auto& row: board) for (auto& e: row) if (e != 0) s.insert(e);
	// Copy to a vector for permuatation
	cardSeq = vector<int>(s.begin(), s.end());
	
	do {
		int cnt = INF; // Count key press

		// 1-2-3
		// Calculate the distance between (r,c) to the nearest cardSeq[i] card
		for (int i = 0; i < cardSeq.size(); ++i) {
			int target = cardSeq[i];
			vector<pair<int, int>> targetPos; 
			// Get the coordinates of target card
			for (int i = 0; i < board.size(); ++i) {
				for (int j = 0; j < board.size(); ++j) {
					if (board[i][j] == target) 
						targetPos.push_back(make_pair(i, j));
				}
			}

//			for (auto& e: targetPos) cout << "(" << e.first << ", " << e.second << ")" << '\n';

			cout << calDist(3,2,make_pair(0,0)) << '\n';
			/*
			// Find shortest way to targetPos[0], targetPos[1] and compare them
			if (calDist(r, c, targetPos[0]) < calDist(r, c, targetPos[1])) {
				// Go to targetPos[0] first

				// Then go to targetPos[1] 
			} else {
				// Go to targetPos[1] first

				// Then go to targetPos[0]
			}
			*/
		} 
		answer = min(answer, cnt);
	} while (next_permutation(cardSeq.begin(), cardSeq.end()));

    return answer;
}

int main() {
	vector<vector<int>> board = {
		{1,0,0,3},
		{2,0,0,0},
		{0,0,0,2},
		{3,0,1,0}
	};
	int r = 1, c = 0;
	cout << solution(board, r, c) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 카드짝맞추기.cpp
*/
