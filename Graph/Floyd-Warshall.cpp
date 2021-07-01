#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
/*
input:
1 2 5
1 4 9
1 5 1
2 3 2
3 4 7
4 5 2
-1 -1 -1
   */
vector<vector<int>> FloydWarshall(int n, vector<vector<int>>& adj) {
	vector<int> row(n + 1, 0);
	vector<vector<int>> dist(n + 1, row);

	// Initialize dist with adj
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dist[i][j] = 0;
			else if(adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//				cout << "k: " << k << " i:" << i << " j:" << j << '\n';
//				for (auto& r: dist) {
//					for (auto& e: r) cout << e << " ";
//					cout << '\n';
//				}
			}
		}
	}
	return dist;
}

int main() {
	int n; cin >> n;
	vector<int> row(n + 1, 0);
	vector<vector<int>> adj(n + 1, row);

	// Initialize adj vector
	while (true) {
		int a, b, w; cin >> a >> b >> w;
		if (a == -1) break;
		adj[a][b] = adj[b][a] = w;
	}

	vector<vector<int>> dist = FloydWarshall(n, adj);
	for (auto& r: dist) {
		for (auto& e: r) cout << e << " ";
		cout << '\n';
	}

	return 0;
}

// g++ -std=c++11 -Wall Floyd-Warshall.cpp
