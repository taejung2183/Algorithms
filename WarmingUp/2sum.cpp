#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool twoPointerSolution(const vector<int>& ori, int target) {
	int lo = 0, hi = ori.size() - 1;
	vector<int> arr(ori.begin(), ori.end());
	sort(arr.begin(), arr.end());
	while (lo < hi) {
		int cand = arr[lo] + arr[hi];
		if (cand == target) return true;
		else if (cand < target) ++lo;
		else --hi;
	}
	return false;
}

bool hashSolution(const vector<int>& ori, int target) {
	unordered_map<int,int> m;

	for (int i = 0; i < ori.size(); ++i) {
		if (m.find(target - ori[i]) != m.end()) return true;
		m[ori[i]] = i;
	}
	return false;
}

int main() {
	vector<int> arr = {3,5,2,1,7,11};
	for (auto& e: arr) cout << e << " "; cout << '\n';
	int target; cin >> target;
	bool ans;

	// Tell if the target can be made up with two elements in the array
	ans = twoPointerSolution(arr, target);
	cout << (ans ? "Possible" : "Impossible") << '\n';

	ans = hashSolution(arr, target);
	cout << (ans ? "Possible" : "Impossible") << '\n';

	return 0;
}
