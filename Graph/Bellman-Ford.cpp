#include <iostream>
#include <vector>

using namespace std;
const int INF = 2100000000;

//   Bellman-Ford algorithm works for all kinds of graphs.
//   Bellman-Ford algorithm finds shortest paths from a starting
//   node to all nodes of the graph, if there's no negative cycle.
//
//   Unlike Dijkstra's algorithm,
//   You can detect if the graph has negative cycle, (which 
//   means there's no shortest path because through the negative 
//   cycle, you can shorten the path infinitely.) by repeat
//   the iteration once more after N-1 iteration. If the result
//   shortened, there's negative cyclce.
   
vector<int> BellmanFord(int n, int s, vector<vector<int>>& edges) {
	vector<int> dist(n + 1, 0);
	for (int i = 1; i <= n; ++i) dist[i] = INF;
	dist[s] = 0;

	// Find the shortest paths to each vertex
	vector<int> v;
	for (int i = 0; i < n - 1; ++i) {
		for (auto& e: edges) {
			v = e;
			int a = v[0], b = v[1], w = v[2];
			dist[b] = min(dist[b], dist[a] + w);
		}
	}

	// Check if there's a negative cycle
	for (auto& e: edges) {
		v = e;
		int a = v[0], b = v[1], w = v[2];
		if (dist[a] + w < dist[b]) {
			cout << "Negative cycle detected" << '\n'; 
			break;
		}
	}

	return dist;
}

int main() {
	int n = 5; // Number of vertices
	int s = 1; // Start edge
	// Weights of edges
	vector<vector<int>> edges = {
		{2,5,2}, 
		{4,2,1}, 
		{2,4,2}, 
		{1,2,-1}, 
		{1,3,4}, 
		{4,3,5}, 
		{2,3,3}, 
		{5,4,-3} 
	};
//	vector<vector<int>> edges = {
//		{1,2,1},
//		{2,3,-1},
//		{3,4,-1},
//		{4,1,-1}
//	};

	vector<int> dist = BellmanFord(n,s,edges);
	for (int i = 1; i <= n; ++i) cout << dist[i] << " "; 
	cout << '\n';

	return 0;
}

// g++ -std=c++11 -Wall Bellman-Ford.cpp
