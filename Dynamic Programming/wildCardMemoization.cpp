#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// -1: initial state, 0: false, 1: true
int cache[101][101];
string wildCard, fileName;

int findMatch2(int w, int f) {
	int& ret = cache[w][f];
	if (ret != -1) return ret;

	// Change to recursion. (Not iteration.)
	while (w < wildCard.size() && f < fileName.size() && 
			(wildCard[w] == '?' || wildCard[w] == fileName[f])) 
		return ret = findMatch2(w + 1, f + 1);

	if (w == wildCard.size()) return ret = (f == fileName.size());

	// 매번 단계마다 *에 아무것도 대응하지 않을 것인지, 한 글자를 더 대응할 것인지를 결정한다.
	if (wildCard[w] == '*') {
		if (findMatch2(w + 1, f) || (f < fileName.size() && findMatch2(w, f + 1)))
			return ret = 1;
	}

	return ret = 0;
}

int findMatch(int w, int f) {
	int& ret = cache[w][f];
	if (ret != -1) return ret;

	// Increase idx until you get to the '*'.
	while ((w < wildCard.size() && f < fileName.size())
			&& (wildCard[w] == '?' || wildCard[w] == fileName[f])) {
		w += 1; f += 1;
	}

	// idx is the last index of the wildCard string.
	if (w == wildCard.size()) return ret = (f == fileName.size());

	if (wildCard[w] == '*') {
		// Iterate util idx + skip <= fileName.size() since idx + 1 can be
		// the index after the end of the string.
		for (int skip = 0; f + skip <= fileName.size(); ++ skip) {
			if (findMatch(w + 1, f + skip)) 
				return ret = 1;
		}
	}

	return ret = 0;
}

int main() {
	int C; cin >> C;
	priority_queue<string, vector<string>, greater<string>> answers;
	vector<string> ans;

	while (C-- > 0) {
		cin >> wildCard;

		int n; cin >> n;
		while (n-- > 0) {
			cin >> fileName;
			for (auto& row: cache) for (auto& e: row) e = -1;

			if (findMatch2(0, 0)) 
				answers.push(fileName);
		}
		while (!answers.empty()) {
			ans.push_back(answers.top());
			answers.pop();
		}
	}
	
	cout << endl;
	for (const auto& e: ans) cout << e << endl; 

	return 0;
}
