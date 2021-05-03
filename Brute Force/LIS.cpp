#include <iostream>
#include <vector>
using namespace std;

// i 보다 큰 값의 j 들로 이루어진 수열을 다시 재귀 입력하면
// 결국 증가 수열의 길이를 얻게 된다. (반환값은 재귀 진입 시마다 1증가)
// j 들로 이루어진 수열에서 다시 부분 수열을 구할 때 이전에
// 선택한 숫자들은 알 필요 없다. (=> 최적 부분 구조를 가진다.)
int LIS_textbook(const vector<int>& seq) {
	if (seq.empty()) return 0;

	int ret = 0;
	for (int i = 0; i < seq.size(); ++i) {
		vector<int> sub;
		for (int j = i + 1; j < seq.size(); ++j) 
			if (seq[i] < seq[j]) sub.push_back(seq[j]);
		ret = max(ret, 1 + LIS2(sub));
	}
	return ret;
}

// pre: index of the number that was picked before current number.
// cur: index of the number that is picked currently.
// len: length of current sequence.
int LIS(const vector<int>& seq, int pre, int cur, int len) {
	cout << "pre idx: " << pre << ", pre val: " << seq[pre] << endl;
	cout << "cur idx: " << cur << ", cur val: " << seq[cur] << endl;
	// Not an increasing sequence.
	if (seq[cur] < seq[pre]) return len - 1;

	// Base case: If you get to the end, return. 
	if (cur == seq.size() - 1) return len;

	int ret = 0;
	// Task piece: Take one of next numbers.
	for (int i = cur + 1; i < seq.size(); ++i) {
		ret = max(ret, LIS(seq, cur, i, len + 1));
	}
	
	return ret;
}

int main() {
	int C; cin >> C;
	vector<int> seq;
	vector<int> answers;

	while (C-- > 0) {
		int len; cin >> len;

		int n;
		for (int i = 0; i < len; ++i) {
			cin >> n;
			seq.push_back(n);
		}

		answers.push_back(LIS(seq, 0, 0, 1));
		//answers.push_back(startLIS(seq));
		seq.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}
