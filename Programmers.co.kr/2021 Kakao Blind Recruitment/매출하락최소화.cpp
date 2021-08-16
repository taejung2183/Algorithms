#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;
const int maxWorkerNum = 300001;

// Equal to sales array
vector<int> workerSales; 
// workerTree[1] has chlid of employee 1
vector<int> workerTree[maxWorkerNum]; 
// dp[x][0]: x is not chosen
// dp[x][1]: x is chosen
int dp[maxWorkerNum][2];

// minSales(x, 0) gives the answer when x is not chosen
// minSales(x, 1) gives the answer when x is chosen
int minSales(int node, int chosen) {
	int& ret = dp[node][chosen];
	if (ret != INF) return ret;

	// Base case: if node has no child, return
	vector<int> child;
	if (!workerTree[node].empty()) child = workerTree[node];
	else return ret = (chosen == 0) ? 0 : workerSales[node];

	// Get the sum of child subtree's optimal choices
	int childSum = 0;
	bool isChildChosen = false;
	for (auto& e: child) {
		// Check if at least one of the child is chosen
		if (minSales(e, 0) > minSales(e, 1)) {
			childSum += minSales(e, 1);
			isChildChosen = true;
		} else {
			childSum += minSales(e, 0);
		}
	}

	ret = childSum;
	// "node" is chosen
	if (chosen) ret += workerSales[node];
	// "node" is not chosen
	else {
		// If no child is chosen, pick one
		if (!isChildChosen) {
			// Why can't we just choose the one with the minimum sales?
			int minDiff = minSales(child[0], 1) - minSales(child[0], 0);
			for (int i = 1; i < child.size(); ++i) 
				minDiff = min(minDiff, minSales(child[i], 1) - minSales(child[i], 0));
			ret += minDiff;
		}
	}

	return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
	// Save as global variable
	workerSales = sales;
	for (auto& e: links) workerTree[e[0]].push_back(e[1]);
	// Insert dummy element to match index with employee number
	workerSales.insert(workerSales.begin(), 0);

	// Initialize dp
	for (auto& e: dp) e[0] = e[1] = INF;

	// Initiate DFS from the root node
    return min(minSales(1, 0), minSales(1, 1));
}

int main() {
	vector<int> sales = {14, 17, 15, 18, 19, 14, 13, 16, 28, 17};
	vector<vector<int>> links = {{10, 8}, {1, 9}, {9, 7}, {5, 4}, {1, 5}, {5, 10}, {10, 6}, {1, 3}, {10, 2}};
//	vector<int> sales = {4,5};
//	vector<vector<int>> links = {{1,2}};

	cout << solution(sales, links) << '\n';;

	return 0;
}

// g++ -std=c++11 -Wall 매출하락최소화.cpp
