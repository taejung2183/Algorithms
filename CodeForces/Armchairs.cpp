#include <bits/stdc++.h>

#define INF 987654321
#define PB push_back
#define NL "\n"

typedef long long ll;

using namespace std;

//int moveArmchair(vector<int> seat) {
//	int ret = 0;
//	for (int i = 0; i < seat.size(); ++i) {
//		// Seat i need to be moved. (Occupied & Unchanged)
//		if (seat[i] == 1 && !changed[i]) {
//			// Starting from i toward both left and right.
//			int t1 = INF, t2 = INF;
//
//			// Left side.
//			int l = i - 1;
//			while (l >= 0) {
//				if (seat[l] == 0 && !changed[l]) {
//					t1 = abs(i - l);
//					break;
//				} else --l;
//			}
//
//			// Right side.
//			int r = i + 1;
//			while (r < seat.size()) {
//				if (seat[r] == 0 && !changed[r]) {
//					t2 = abs(i - r);
//					break;
//				} else ++r;
//			}
//			
//			// Clear current seat and calculate the distance while occupying the closest seat.
//			seat[i] = 0; changed[i] = true;
//			if(t1 >= t2) { seat[r] = 1; changed[r] = true; ret += t2; }
//			else { seat[l] = 1; changed[l] = true; ret += t1; }
//		}
//	}
//	return ret;
//}

//int cache[5000];
vector<int> seat;

int moveArmchair1(vector<bool> changed, int cur, int totalDist) {
	if (cur == seat.size()) return totalDist;

	int ret = INF;
	for (int i = cur; i < seat.size(); ++i) {
		if (seat[i] == 1 && !changed[i]) {
			for (int j = 0; j < seat.size(); ++j) {
				// Find available seat.
				if (seat[j] == 0 && !changed[j]) {
					changed[i] = changed[j] = true;
					ret = min(ret, moveArmchair1(changed, cur + 1, totalDist + abs(cur - i)));
					changed[i] = changed[j] = false;
				}
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	vector<bool> changed;

	int n; cin >> n;
	seat = vector<int>(n, 0); for (auto& e: seat) cin >> e;
	changed = vector<bool>(n, false);
//	memset(cache, -1, sizeof(cache));

//	cout << startMoving(changed) << NL;
	cout << moveArmchair1(changed, 0, 0) << NL;

	return 0;
}

//	g++ -std=c++11 -Wall Armchairs.cpp -o Armchairs
