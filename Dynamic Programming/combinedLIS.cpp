#include <iostream>
#include <vector>
using namespace std;

int cache[100][100];
int lenA, lenB;
vector<int> seqA, seqB;

int combinedLIS(int idxA, int idxB) {
	int& ret = cache[idxA][idxB];
	if (ret != -1) return ret;

	// Starts with two letters from each sequence.
	ret = 2;
	int maxElement = max(seqA[idxA], seqB[idxB]);

	for (int nextA = idxA + 1; nextA < lenA; ++nextA) {
		if (maxElement < seqA[nextA])
			ret = max(ret, combinedLIS(nextA, idxB) + 1);
	}

	for (int nextB = idxB + 1; nextB < lenB; ++nextB) {
		if (maxElement < seqB[nextB])
			ret = max(ret, combinedLIS(idxA, nextB) + 1);
	}

	return ret;
}

int startLIS() {
	int ret = 0;
	for (int idxA = 0; idxA < lenA; ++idxA) 
		for (int idxB = 0; idxB < lenB; ++idxB) 
			ret = max(ret, combinedLIS(idxA, idxB));
	return ret;
}

int main() {
	int C; cin >> C;
	vector<int> answers;
	 
	while (C-- > 0) {
		// Reset cache.
		for (auto& row: cache) for (auto& e: row) e = -1;

		cin >> lenA; cin >> lenB;
		int n;
		for (int i = 0; i < lenA; ++i) {
			cin >> n; 
			seqA.push_back(n);
		}
		for (int i = 0; i < lenB; ++i) {
			cin >> n; 
			seqB.push_back(n);
		}

		answers.push_back(startLIS());
		seqA.clear();
		seqB.clear();
	}

	for (const auto& e: answers) cout << e << endl;

	return 0;
}
