#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// comb function makes the combinations of picking n numbers of elements in the string s and store it to combs vector
vector<string> combs;

vector<string> solution(vector<string> orders, vector<int> course) {

    vector<string> answer;
	unordered_map<string, int> popularity[11];

	for (auto& e: orders) sort(e.begin(), e.end());

	// Extract all the combination
	for (auto& order: orders) {
		for (int i = 1; i < (1 << order.size()); ++i) {
			string comb = "";

			for (int j = 0; j < order.size(); ++j) 
				if (i & (1 << j)) comb += order[j];

			popularity[comb.size()][comb]++;
		}
	}

	for (auto& e: course) {
		int maxPop = 0;
		for (auto& m: popularity[e]) 
			maxPop = max(maxPop, m.second);

		if (maxPop < 2) continue;

		for (auto& m: popularity[e]) 
			if (m.second == maxPop) answer.push_back(m.first);
	}

	// Sort in dictionary order
	sort(answer.begin(), answer.end());
    return answer;
}

int main() {
	vector<string> orders = {
		{"ABCFG"},
		{"AC"},
		{"CDE"},
		{"ACDE"},
		{"BCFG"},
		{"ACDEH"},
	};
	vector<int> course = {2,3,4};
	vector<string> answer = solution(orders, course);
	for (auto& e: answer) cout << e << " "; cout << '\n';
	return 0;
}

// g++ -std=c++11 -Wall 메뉴리뉴얼2.cpp -o 메뉴리뉴얼2
