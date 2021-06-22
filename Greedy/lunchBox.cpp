#include <bits/stdc++.h>

using namespace std;

vector<int> M, E;

int lunchBox() {
	vector<pair<int, int>> EM;
	// push -E[i] to sort it in descending order
	for (int i = 0; i < M.size(); ++i) EM.push_back(make_pair(-E[i], M[i]));
	// Sort by descending order of eating duration
	sort(EM.begin(), EM.end());

	int ret = 0, beginEat = 0;
	for (int i = 0; i < EM.size(); ++i) {
		// Add microwave time
		beginEat += EM[i].second;
		ret = max(ret, beginEat + (-EM[i].first));
	}

	return ret;
}

int main() {
	int T; cin >> T;
	int n1, n2;
	vector<int> answers;

	while (T--) {
		cin >> n1; n2 = n1;

		int t;
		while (n1--) { cin >> t; M.push_back(t); }
		while (n2--) { cin >> t; E.push_back(t); }

		answers.push_back(lunchBox());
		M.clear(); E.clear();
	}
	for (auto& e: answers) cout << e << '\n';

	return 0;
}

// g++ -std=c++11 -Wall lunchBox.cpp
