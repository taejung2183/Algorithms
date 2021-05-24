#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> triangle;
int cache[100][100];
int n;

int trianglePathMemoization(int y, int x) {
	// Base case
	if (y == triangle.size() - 1) return triangle[y][x];

	// Memoization
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = triangle[y][x] + max(trianglePathMemoization(y + 1, x), trianglePathMemoization(y + 1, x + 1));
}

int countCache[100][100];

int count(int y, int x) {
	if (y == n - 1) return 1;

	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0;

	if (trianglePathMemoization(y + 1, x + 1) >= trianglePathMemoization(y + 1, x)) ret += count(y + 1, x + 1);
	if (trianglePathMemoization(y + 1, x + 1) <= trianglePathMemoization(y + 1, x)) ret += count(y + 1, x);

	return ret;
}

int main() { 
	int C; cin >> C;
	vector<int> answers;

	while (C-- > 0) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));

		vector<int> row;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				int num; cin >> num;
				row.push_back(num);
			}
			triangle.push_back(row);
			row.clear();
		}
		
		answers.push_back(count(0, 0));
		triangle.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}

// g++ -std=c++11 -Wall triPathCnt.cpp -o triPathCnt
