#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
/*
   우선, 보석의 종류를 모르니까 set에 저장해서 보석 종류의 가짓수를 알아낸다.
   
   완전 탐색: gems 벡터를 순회하면서 set의 보석 종류를 다 모으면 길이를 측정해서 
   가장 짧은 길이를 반환.
   n개의 입력 (최대 100k). 최악의 경우 보석의 종류가 100k 라고 하면 100k^100k 의 
   시간 복잡도? 10,000,000,000

   분할 정복: 절반으로 나누어 왼편 혹은 오른편에 모든 종류를 포함하는 배열이 있거나
   중간에 걸쳐져 존재한다.
   */
vector<string> g;
set<string> kind;

vector<int> gemShop(int lo, int hi) {
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
		vector<int> ret = {lo, hi};
		return ret;
	}
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
