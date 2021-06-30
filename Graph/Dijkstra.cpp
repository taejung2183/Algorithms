#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int INF = 2100000000;
/*
input:
5 1
1 2 5
1 4 9
1 5 1
2 3 2
2 1 5
3 2 2
3 4 6
4 3 6
4 1 9
4 5 2
5 1 1
5 4 2
-1 -1 -1
*/
map<int, vector<pair<int, int>>> adj;

vector<int> Dijkstra(int n, int s) {
	vector<int> dist(n + 1, INF);
	vector<bool> processed(n + 1, false);
	priority_queue<pair<int,int>> q;

	dist[s] = 0;
	q.push({0, s});

	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;

		for (auto& e: adj[a]) {
			int b = e.first, w = e.second;
			dist[b] = min(dist[b], dist[a] + w);
			// priority queue sorts in descending order
			q.push({-dist[b], b});
		}
	}
	return dist;
}

int main() {
	int n, s; // Number of vertices, starting point
	cin >> n >> s; 

	// adj[a].push_back(make_pair(b, w));
	// It takes w weight from a to b
	while (true) {
		int a, b, w; cin >> a >> b >> w;
		if (a == -1) break;
		adj[a].push_back(make_pair(b, w));
	}

	vector<int> path = Dijkstra(n, s);
	for (int i = 1; i <= n; ++i) cout << path[i] << " ";
	cout << '\n';

	return 0;
}

// g++ -std=c++11 -Wall Dijkstra.cpp
