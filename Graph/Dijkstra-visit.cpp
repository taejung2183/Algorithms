#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<int> Dijkstra(int n, int s, const vector<pair<int, int>> adj[]) {
	vector<int> dist(n + 1, INF);
	vector<int> visited(n + 1, false);
	priority_queue<pair<int, int>> cheapest;

	dist[s] = 0;
	cheapest.push({0, s});

	while (!cheapest.empty()) {
		int s = cheapest.top().second;
		cheapest.pop();

		if (visited[s]) continue;
		visited[s] = true;

		cout << s << " ";

		for (auto& e: adj[s]) {
			int d = e.first, w = e.second;

			// Push to pq only when it's updated
			if (dist[d] > dist[s] + w) {
				dist[d] = dist[s] + w;
				cheapest.push({-dist[d], d});
			}
		}
	}
	return dist;
}

int main() {
	vector<vector<int>> edges1 = {
		{1,2,4},
		{1,8,8},
		{2,1,4},
		{2,8,11},
		{2,3,8},
		{3,2,8},
		{3,9,2},
		{3,6,4},
		{3,4,7},
		{4,3,7},
		{4,6,14},
		{4,5,9},
		{5,4,9},
		{5,6,10},
		{6,5,10},
		{6,4,14},
		{6,3,4},
		{6,7,3},
		{7,6,2},
		{7,8,1},
		{7,9,6},
		{8,1,8},
		{8,2,11},
		{8,9,7},
		{8,7,1},
		{9,8,7},
		{9,3,2},
		{9,7,6}
	};
	vector<vector<int>> edges2 = {
		{1, 2, 5},
		{1, 4, 9},
		{1, 5, 1},
		{2, 3, 2},
		{2, 1, 5},
		{3, 2, 2},
		{3, 4, 6},
		{4, 3, 6},
		{4, 1, 9},
		{4, 5, 2},
		{5, 1, 1},
		{5, 4, 2}
	};

	int n1 = 9, s1 = 1;
	int n2 = 5, s2 = 1;
	vector<pair<int, int>> adj1[n1 + 1];
	vector<pair<int, int>> adj2[n2 + 1];

	// It takes w weight from s to d
	for (auto& e: edges1) {
		int s = e[0], d = e[1], w = e[2];
		adj1[s].push_back({d, w});
	}

	for (auto& e: edges2) {
		int s = e[0], d = e[1], w = e[2];
		adj2[s].push_back({d, w});
	}

	clock_t start, end;
	vector<int> ans;

	start = clock();
	ans = Dijkstra(n1, s1, adj1);
	end = clock();

	cout << "edges 1 execution time: " << (double)(end - start) << '\n';
	for (int i = 1; i <= n1; ++i) cout << ans[i] << " "; cout << '\n';

	start = clock();
	ans = Dijkstra(n2, s2, adj2);
	end = clock();

	cout << "edges 2 execution time: " << (double)(end - start) << '\n';
	for (int i = 1; i <= n2; ++i) cout << ans[i] << " "; cout << '\n';

	return 0;
}

// g++ -std=c++11 -Wall Dijkstra-visit.cpp -o Dijkstra-visit
