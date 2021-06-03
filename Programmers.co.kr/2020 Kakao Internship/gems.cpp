#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
	unordered_map<string, int> m;
	const unordered_set<string> s(gems.begin(), gems.end());
	int n = gems.size();
	int l = 0, r = 0;

	while (true) {
		m[gems[r]] += 1;
		if (m.size() == s.size()) break;
		++r;
	}
	int min = r - l;
	answer = {l + 1, r + 1};

	while (r < n) {
		string tmp = gems[l];
		m[tmp] -= 1;
		++l;
		if (m[tmp] == 0) {
			++r;
			while (r < n) {
				m[gems[r]] += 1;
				if (!tmp.compare(gems[r])) break;
				++r;
			}
		}
		if (r - l < min) {
			min = r - l;
			answer = {l + 1, r + 1};
		}
	}

    return answer;
}

int main() {
	vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<int> ans = solution(gems);
	cout << "[" << ans[0] << ", " << ans[1] << "]" << '\n';
	return 0;
}

// g++ -std=c++11 -Wall gems.cpp -o gems
