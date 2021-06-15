#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 2100000000;

vector<vector<int>> b;
int len;
bool visited[25][25];
// Only works with this sequence
const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};
// This doesn't work...(or any other sequence as well)
// const int dy[4] = {1,0,-1,0};
// const int dx[4] = {0,1,0,-1};

struct Car {
	int cy, cx, ly, lx, cost;
};

// DFS with stack
// Utilize board input vector as cache memory
int dfsStack() {
	int ret = INF;

	stack<Car> s;
	s.push({0,0,0,0,0});
	b[0][0] = 0;

	while (!s.empty()) {
		Car car = s.top();
		s.pop();
		// Arrived
		if (car.cy == len - 1 && car.cx == len - 1) ret = min(ret, car.cost);

		// Check every direction from current coordinate
		for (int i = 0; i < 4; ++i) {
			int ny = car.cy + dy[i];
			int nx = car.cx + dx[i];

			// (ny, nx) is available
			if (ny >= 0 && ny < len && nx >= 0 && nx < len && b[ny][nx] != 1) {
				int c = (ny != car.ly && nx != car.lx) ? 600 : 100;
				// Update only when it's cheaper
				if (car.cost + c <= b[ny][nx]) {
					s.push({ny, nx, car.cy, car.cx, car.cost + c});
					b[ny][nx] = car.cost + c;
				}
			}
		}
		// Test print code
//		cout << "cy: " << car.cy << " cx: " << car.cx << '\n';
//		for (int i = 0; i < b.size(); ++i) {
//			for (int j = 0; j < b.size(); ++j) {
//				if (b[i][j] == INF) printf("%5c ", '-');
//				else if (b[i][j] == 1) printf("%5c ", 'X');
//				else printf("%5d ", b[i][j]);
//			} cout << '\n';
//		}
	}

	return ret;
}

// Recursive dfs
int dfsRecursion(int cy, int cx, int ly, int lx, int cost) {
	if (cy == len - 1 && cx == len - 1) return cost;

	int ret = INF;
	for (int i = 0; i < 4; ++i) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny >= 0 && ny < len && nx >= 0 && nx < len
				&& !b[ny][nx] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			int c = (ny != ly && nx != lx) ? 600 : 100;
			ret = min(ret, dfsRecursion(ny, nx, cy, cx, cost + c));
			visited[ny][nx] = 0;
		}
	}
	return ret;
}

// DFS memoization

// How I usually did before:
// Memorize how much will it cost to get to the destination from (y,x)
// Thus, cache[0][0] will be the answer eventually

// How am I doing it now:
// Memorize how much did you spend to get to the (y,x)
// Thus, cache[n-1][n-1] will be the answer eventually
// (cache at the destination has got the answer)
// When you get to the (y,x) and if you spent more than in the cache currently,
// prune that recurssive task by return;

// {0, 0, 0, 0, 0}
// {0, 1, 1, 1, 0}
// {0, 0, 1, 0, 0}
// {1, 0, 0, 0, 1}
// {0, 1, 1, 0, 0}
// If you start downward, you spend 2100 to get to (3,3)
// If you start to the right side, you spend 2300 to get to (3,3) so this recurssive task will be pruned.
// However, the former one spend 3300 to get to the destination,
// on the other hand, the latter one spend 3000 to get to the destination.

// This means your pruning strategy is imperfect.

int cost[25][25];
void dp(int cy, int cx, int ly, int lx, int sum) {
	// Prune if the current sum is worse(bigger) than the one in memory
	if (sum > b[cy][cx]) return;
			
	// Memorize current answer
	b[cy][cx] = sum;

	// Arrived
	if (cy == len - 1 && cx == len - 1) return;

	for (int i = 0; i < 4; ++i) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];

		if (ny >= 0 && ny < len && nx >= 0 && nx < len && b[ny][nx] != 1) {
			int val = (ny != ly && nx != lx) ? 600 : 100;
			dp(ny, nx, cy, cx, sum + val);
		}
	}
}

int solution(vector<vector<int>> board) {
    int answer = 0;

	b = vector<vector<int>> (board); len = b.size();
	for (auto& row: b) for (auto& e: row) if (!e) e = INF; 
	for (auto& row: visited) for (auto& e: row) e = false;

//	answer = dfsRecursion(0, 0, 0, 0, 0);
//	answer = dfsStack();
	dp(0,0,0,0,0);
	answer = b[len - 1][len - 1];
	
    return answer;
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

// g++ -std=c++11 -Wall racingRoadDFS.cpp -o racingRoadDFS
