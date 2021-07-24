#include <iostream>
#include <algorithm>
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
*/

vector<vector<int>> b;
int dr[4] = {0,1,0,-1};
int dc[4] = {-1,0,1,0};
int calDist(int r, int c, int tr, int tc) {
	// Already at the target
	if (r == tr && c == tc) return 0;

	vector<vector<int>> cost(b);
	for (auto& r: cost) for (auto& e: r) e = INF;
	queue<pair<pair<int,int>,int>> q;

	q.push({{r, c}, 0});
	cost[r][c] = 0;

	while (!q.empty()) {
		pair<pair<int,int>,int> cur = q.front(); q.pop();
		int cr = cur.first.first;
		int cc = cur.first.second;
		int cnt = cur.second;

		// Normal move
		for (int i = 0; i < 4; ++i) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			// Range check
			if (nr < 0 || nc < 0 || nr >= b.size() || nc >= b.size()) continue;

			if (cost[nr][nc] < cnt + 1) continue;
			q.push({{nr, nc}, cnt + 1});
			cost[nr][nc] = cnt + 1;
		}

		// Ctrl move
		for (int i = 0; i < 4; ++i) {
			int dirR = dr[i];
			int dirC = dc[i];
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			// Range check 
			if (nr < 0 || nc < 0 || nr >= b.size() || nc >= b.size()) continue;
			
			// Repeat moving if you are standing on zero
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

			// Update only when its better
			if (cost[nr][nc] < cnt + 1) continue;
			q.push({{nr, nc}, cnt + 1});
			cost[nr][nc] = cnt + 1;
		}
	}
	return cost[tr][tc];
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;
	set<int> s;
	vector<int> cardSeq; // Hold sequences of cards

	// Check what kind of card in the board
	for (auto& row: board) for (auto& e: row) if (e != 0) s.insert(e);
	// Copy to a vector for permuatation
	cardSeq = vector<int>(s.begin(), s.end());

	do {
		int cnt = 0;
		// Restore the original starting point
		int rr = r, cc = c;
		// New board for new sequence
		b = board;

		for (int i = 0; i < cardSeq.size(); ++i) {
			int t = cardSeq[i];
			vector<pair<int, int>> target;

			// Get the coordinates of target card pair
			for (int i = 0; i < board.size(); ++i) 
				for (int j = 0; j < board.size(); ++j) 
					if (board[i][j] == t) target.push_back({i, j});

			int tr1 = target[0].first, tc1 = target[0].second; 
			int tr2 = target[1].first, tc2 = target[1].second;

			// Compare (tr1,tc1) -> (tr2,tc2) and (tr2,tc2) -> (tr1,tc1)
			int route1 = calDist(rr, cc, tr1, tc1) + calDist(tr1, tc1, tr2, tc2);
			int route2 = calDist(rr, cc, tr2, tc2) + calDist(tr2, tc2, tr1, tc1);

			if (route1 < route2) {
				cnt += route1;
				rr = tr2; cc = tc2;
			} else {
				cnt += route2;
				rr = tr1; cc = tc1;
			}

			// Pressing enter
			cnt += 2;
			// Remove the cards
			b[tr1][tc1] = b[tr2][tc2] = 0;
		} 
		answer = min(answer, cnt);
	} while (next_permutation(cardSeq.begin(), cardSeq.end()));

    return answer;
}

int main() {
//	vector<vector<int>> board = {
//		{1,0,0,3},
//		{2,0,0,0},
//		{0,0,0,2},
//		{3,0,1,0}
//	};
//	int r = 1, c = 0;
	vector<vector<int>> board = {
		{3,0,0,2},
		{0,0,1,0},
		{0,1,0,0},
		{2,0,0,3}
	};
	int r = 0, c = 1;
	cout << solution(board, r, c) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 카드짝맞추기.cpp
*/
