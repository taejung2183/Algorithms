#include <iostream>
#include <string>
#include <vector>
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
		if (idx == wildCard.size() - 1) return true;
		for (int skip = 0; idx + skip < fileName.size(); ++ skip) {
			// idx is the last index.
			if (wildCard[idx + 1] == fileName[idx + skip])
				return findMatch(wildCard.substr(idx + 1), fileName.substr(idx + skip));
		}
	}

	return false;
}

int main() {
	int C; cin >> C;
	string wildCard, fileName;
	vector<string> answers;

	while (C-- > 0) {
		cin >> wildCard;

		int n; cin >> n;
		while (n-- > 0) {
			cin >> fileName;
			if (findMatch(wildCard, fileName)) 
				answers.push_back(fileName);
		}
	}

	cout << "\n--ANSWERS--" << endl;
	for (const auto& e: answers) cout << e << endl;

	return 0;
}
