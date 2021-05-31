#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> g;
set<string> kind;

vector<int> gemShop(int lo, int hi) {
	vector<int> ret;
	// Base case: If lo~hi include all kinds of gem, return [lo,hi]
	bool allIncluded = true;
	for (auto kindIt = kind.begin(); kindId != kind.end(); ++kindIt) {
		auto gemIt = find(g.begin(), g.end(), *kindIt);
		if (gemIt == g.end()) {
			allIncluded = false;
			break;
		}
	}
	if (allIncluded) {
		ret = vector<int>() {lo, hi};
		return ret;
	}

	int mid = (lo + hi) / 2;
	vector<int> left = gemShop(lo, mid);
	vector<int> right = gemShop(mid + 1, hi);
	ret = min(left, right);

	int l = mid, r = mid + 1;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
	g = gems
	kind = set<string>(gems.begin(), gems.end());
	answer = gemShop(0, gems.size());
    return answer;
}

int main() {
	vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<int> ans = solution(gems);
	cout << "[" << ans[0] << ", " << ans[1] << "]" << '\n';
	return 0;
}

// g++ -std=c++11 -Wall gems.cpp -o gems
