#include <iostream>
#include <vector>
using namespace std;

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
