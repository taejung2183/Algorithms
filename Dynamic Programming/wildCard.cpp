#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool findMatch(const string& wildCard, const string& fileName) {
	int idx = 0;

	// Increase index until you get to the '*'.
	while ((idx < wildCard.size() && idx < fileName.size())
			&& (wildCard[idx] == '?' || wildCard[idx] == fileName[idx]))
		idx += 1;

	// idx is the last index of the wildCard string.
	if (idx == wildCard.size()) return idx == fileName.size();

	if (wildCard[idx] == '*') {
		for (int skip = 0; idx + skip <= fileName.size(); ++ skip) {
			if (findMatch(wildCard.substr(idx + 1), fileName.substr(idx + skip)))
				return true;
		}
	}

	return false;
}

int main() {
	int C; cin >> C;
	string wildCard, fileName;
	priority_queue<string, vector<string>, greater<string>> answers;
	vector<string> ans;

	while (C-- > 0) {
		cin >> wildCard;

		int n; cin >> n;
		while (n-- > 0) {
			cin >> fileName;
			if (findMatch(wildCard, fileName) == 1) 
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
