#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int,int> twoPointerSolution(const vector<int>& ori, int target) {
	int lo = 0, hi = ori.size() - 1;
	vector<int> arr(ori.begin(), ori.end());
	sort(arr.begin(), arr.end());
	while (lo < hi) {
		int cand = arr[lo] + arr[hi];
		if (cand == target) return make_pair(lo, hi);
		else if (cand < target) ++lo;
		else --hi;
	}
	return make_pair(-1, -1);
}

int main() {
	vector<int> arr = {3,5,2,1,7,11};
	int target; cin >> target;

	// Return the indices of two elements
	// that can add up to target.

	pair<int,int> ans = twoPointerSolution(arr, target);
	cout << ans.first << " " << ans.second << '\n';

//	ans = hashSolution(arr, target);
//	cout << ans[0] << " " << ans[1] << '\n';

	return 0;
}
