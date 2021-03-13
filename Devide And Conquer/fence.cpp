#include <iostream>
#include <vector>
using namespace std;

int fence(vector<int> woods, int lo, int hi) {
	// Base case: If only one wood left, return the size of it.
	if (hi == lo) return woods.at(lo);

	// Choose the bigger one between the left and right woods.
	int mid = (lo + hi) / 2;
	int leftWood = fence(woods, lo, mid);
	int rightWood = fence(woods, mid + 1, hi);

	int ret = max(leftWood, rightWood);

	int left = mid, right = mid + 1;
	int length = 2, height = min(woods.at(left), woods.at(right));
	ret = max(ret, length * height);

	while (lo < left || right < hi) {
		// Expand to the right side.
		if (right < hi && (left == lo || woods.at(left - 1) < woods.at(right + 1))) {
			right += 1;
			// If the new wood's height is lower than the current fence,
			// fence expansion will be lower than the current height.
			if (woods.at(right) < height) height = woods.at(right);
		// Expand to the left side.
		} else { 
			left -= 1;
			if (woods.at(left) < height) height = woods.at(left);
		}
		length += 1;
		ret = max(ret, length * height);
	}

	return ret;
}

int main() {
	int C; cin >> C;
	int woodNum;
	vector<int> answers, woods;

	while (C-- > 0) {
		cin >> woodNum;
		woods = vector<int>(woodNum);
		for (auto& e: woods) cin >> e;
		
		answers.push_back(fence(woods, 0, woodNum - 1));
	}

	for (const auto& e: answers) cout << e << endl;
	return 0;
}
