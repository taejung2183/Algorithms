#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2100000000;

vector<vector<int>> b; int len;
const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

struct Car { int cy, cx, ly, lx, cost; };

// BFS with queue
int bfs() {
	int ret = INF;
	
	queue<Car> q;
	q.push({0,0,0,0});
	b[0][0] = 0;

	while (!q.empty()) {
		Car car = q.front();
		q.pop();

		// Arrived
		if (car.cy == len - 1 && car.cx == len - 1) ret = min(ret, car.cost);

		// Check every directions 
		for (int i = 0; i < 4; ++i) {
			int ny = car.cy + dy[i];
			int nx = car.cx + dx[i];

			// (ny, nx) is available
			if (ny >= 0 && ny < len && nx >= 0 && nx < len && b[ny][nx] != 1) {
				int c = (ny != car.ly && nx != car.lx) ? 600 : 100;
				// Update only when it's cheaper
				if (car.cost + c <= b[ny][nx]) {
					q.push({ny, nx, car.cy, car.cx, car.cost + c});
					b[ny][nx] = car.cost + c;
				}
			}
		}		
		// Test print code
		cout << "cy: " << car.cy << " cx: " << car.cx << '\n';
		for (int i = 0; i < b.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				if (b[i][j] == INF) printf("%5c ", '-');
				else if (b[i][j] == 1) printf("%5c ", 'X');
				else printf("%5d ", b[i][j]);
			} cout << '\n';
		}
	}
	return ret;
}

int solution(vector<vector<int>> board) {
	b = vector<vector<int>> (board); len = b.size();
	for (auto& row: b) for (auto& e: row) if (!e) e = INF; 

    return bfs();
}

int main() {
	vector<int> answers;
	vector<vector<int>> board1 = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	vector<vector<int>> board2 = {
		{0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1},
		{0,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,0},
		{1,0,0,0,0,0,0,0}
	};
	vector<vector<int>> board3 = {
		{0,0,1,0},
		{0,0,0,0},
		{0,1,0,1},
		{1,0,0,0},
	};
	vector<vector<int>> board4 = {
		{0,0,0,0,0,0},
		{0,1,1,1,1,0},
		{0,0,1,0,0,0},
		{1,0,0,1,0,1},
		{0,1,0,0,0,1},
		{0,0,0,0,0,0},
	};
	vector<vector<int>> board5 = {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 1, 0},
		{0, 0, 1, 0, 0},
		{1, 0, 0, 0, 1},
		{0, 1, 1, 0, 0},
	};
	
	answers.push_back(solution(board1));
	answers.push_back(solution(board2));
	answers.push_back(solution(board3));
	answers.push_back(solution(board4));
	answers.push_back(solution(board5));

	for (auto& e: answers) cout << e << '\n';

	return 0;
}

// g++ -std=c++11 -Wall racingRoadBFS.cpp -o racingRoadBFS
