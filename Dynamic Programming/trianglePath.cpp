#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> triangle;

void printTriangle(const vector<vector<int>>& triangle) {
	cout << endl;
	for (const auto& row: triangle) {
		for (const auto& e: row) 
			cout << e << " ";
		cout << endl;
	}
}

// Maximum input is 100.
int cache[100][100];

int trianglePathMemoization(int y, int x) {
	// Base case
	if (y == triangle.size() - 1) return triangle[y][x];

	// Memoization
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = triangle[y][x] + max(trianglePathMemoization(y + 1, x), trianglePathMemoization(y + 1, x + 1));
}

int trianglePath(int y, int x, int sum) {
	// Base case: When you get the the lowest row, return sum.
	if (y == triangle.size() - 1) return sum += triangle[y][x];

	// Add current value.
	sum += triangle[y][x];

	// Task piece: Take each path and get the maximum sum.
	return sum = max(trianglePath(y + 1, x, sum), trianglePath(y + 1, x + 1, sum));
}

int main() { 
	int C; cin >> C;
	vector<int> answers;

	while (C-- > 0) {
		int len; cin >> len;
		memset(cache, -1, sizeof(cache));

		vector<int> row;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < i + 1; ++j) {
				int num; cin >> num;
				row.push_back(num);
			}
			triangle.push_back(row);
			row.clear();
		}
		
		answers.push_back(trianglePathMemoization(0, 0));
		//answers.push_back(trianglePath(0, 0, 0));
		triangle.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}
