#include <iostream>
#include <vector>
using namespace std;

int len;
int cache[500];
vector<int> seq;

int lisMemoization(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < seq.size(); ++next) {
		if (seq[start] < seq[next])
			ret = max(ret, lisMemoization(next) + 1);
	}

	return ret;
}

// LIS Starts from all of the index.
int startLIS() {
	int ret = 0;
	for (int i = 0; i < seq.size(); ++i) 
		ret = max(ret, lisMemoization(i));
	return ret;
}

int main() {
	int C; cin >> C;
	vector<int> answers;
	 
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));

		cin >> len;
		int n;
		for (int i = 0; i < len; ++i) {
			cin >> n; 
			seq.push_back(n);
		}

		answers.push_back(startLIS());
		seq.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}
