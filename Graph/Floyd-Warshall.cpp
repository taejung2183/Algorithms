#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<vector<int>> FloydWarshall(const vector<vector<int>>& adj) {
	int n = adj.size();
	vector<vector<int>> dist(n, vector<int>(n, 0));

	// Initialize dist with adj
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (i == j) dist[i][j] = 0;
			else if(adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = INF;
		}
	}

	for (int k = 1; k < n; ++k) {
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	return dist;
}

int main() {
	int n = 5; // # of vertices
	int edges[][3] = {
		{1, 2, 2},
		{2, 3, 6},
		{3, 2, 7},
		{4, 3, 1},
		{4, 5, 3},
		{5, 1, 1},
		{5, 2, 4},
	}
	vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

	// Initialize adjacency matrix
	for (const auto& e: edges) {
		int s = e[0], d = e[1], w = e[2];
		adj[s][d] = w;
	}

	vector<vector<int>> dist = FloydWarshall(adj);

	// Print answer
	for (auto& r: dist) {
		for (auto& e: r) {
			if (e == INF) printf("  %2s", "∞");
			else printf(" %2d", e);
		} cout << '\n';
	}

	return 0;
}

// g++ -std=c++11 -Wall Floyd-Warshall.cpp
