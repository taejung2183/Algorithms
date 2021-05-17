#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> t, vector<int> r) {
    vector<int> answer;
	int minIdx = min_element(t.begin(), t.end()) - t.begin();
	int maxIdx = max_element(t.begin(), t.end()) - t.begin();

	//cout << minIdx << " " << maxIdx << endl;

	// 0 1 2 3 
	for (int i = t[minIdx]; i <= t[maxIdx]; ++i) {
		for (int j = 0; j < t.size(); ++j) {
			if (i == j) continue;
			// 
			if (t[i] == t[j]) {
				
			}
		}
	}

    return answer;
}

int main() {
	vector<int> t = {0,1,3,0};
	vector<int> r = {0,1,2,3};
	vector<int> ans = solution(t, r);
	for (auto& e: ans) cout << e << " ";
	cout << endl;
	return 0;
}
