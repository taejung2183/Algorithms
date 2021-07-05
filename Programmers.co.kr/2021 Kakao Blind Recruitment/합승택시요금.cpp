#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Too large number makes an over flow
const int INF = 98765432;

// Floyd-Warshall algorithm
// d[i][j] = Minimum fare for i to j
vector<vector<int>> d;
void calDist(int n, vector<vector<int>>& adj) {
	vector<int> row(n + 1, 0);
	d = vector<vector<int>>(n + 1, row);

	// Initialize distance array
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) d[i][j] = 0;
			else if(adj[i][j]) d[i][j] = adj[i][j];
			else d[i][j] = INF;
		}
	}

	// Calculate shortest path for each vertices
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
	vector<int> row(n + 1, 0);
	vector<vector<int>> adj(n + 1, row);

	// Make an adjacent array
	for (auto& e: fares) {
		vector<int> v = e;
		int a = v[0], b = v[1], w = v[2];
		adj[a][b] = adj[b][a] = w;
	}

	calDist(n, adj);

	// Find the minimum value of d[s][k] + d[k][a] + d[k][b]
	answer = INF;
	for (int k = 1; k <= n; ++k) 
		answer = min(answer, d[s][k] + d[k][a] + d[k][b]);
    return answer;
}

int main() {
	int n = 6, s = 4, a = 6, b = 2;
	vector<vector<int>> fares = {
		{4, 1, 10}, 
		{3, 5, 24}, 
		{5, 6, 2}, 
		{3, 1, 41}, 
		{5, 1, 24}, 
		{4, 6, 50}, 
		{2, 4, 66}, 
		{2, 3, 22}, 
		{1, 6, 25}
	};
	cout << solution(n,s,a,b,fares) << '\n';
	return 0;
}

// g++ -std=c++11 -Wall 합승택시요금.cpp
