#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// comb function makes the combinations of picking n numbers of elements in the string s and store it to combs vector
vector<string> combs;
void comb(const string& s, int n, string& picked) {
	// s must be sorted string 

	// Base case
	if (n == 0) {
		combs.push_back(picked);
		return;
	}

	// Force the sequence in sorted order
	int smallest = picked.empty() ? 0 : (find(s.begin(), s.end(), picked.back()) - s.begin()) + 1;

	for (int i = smallest; i < s.size(); ++i) {
		picked.push_back(s[i]);
		comb(s, n - 1, picked);
		picked.pop_back();
	}
}

// Decreasing order
bool cmp(pair<string, int>& i, pair<string, int>& j) { return (i.second > j.second); }

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
	map<string, int> m;
	string s;

	// Sort orders to guarantee the sequence of the combinations is always in dictionary order
	for (auto& e: orders) sort(e.begin(), e.end());

	for (auto& e: course) {
		for (int i = 0; i < orders.size(); ++i) {
			combs.clear();
			comb(orders[i], e, s);
			for (auto& e: combs) ++m[e];
		}

		// Find the maximum value greater than 1
		int maxVal = 0;
		for (auto& e: m) if (e.second > 1) maxVal = max(maxVal, e.second);

		// All the elements that have maxVal are the answer
		for (auto& e: m) if (e.second == maxVal) answer.push_back(e.first);

		m.clear();
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

// g++ -std=c++11 -Wall 메뉴리뉴얼.cpp -o 메뉴리뉴얼
