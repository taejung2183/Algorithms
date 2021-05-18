#include <bits/stdc++.h>

#define INF 987654321
#define PB push_back
#define NL "\n"

typedef long long ll;

using namespace std;

/*
   Basic idea: When you find occupied seat search empty seat toward both side from it.
   What if both side's answers are same? 
   current : Fixed to occupy the seat on the left.
   => Not working, When you fix to occupy the right side, the answer differs.

   Complete search: Try all the possible case that makes all the pre-occupied seats to be vacant. 
 */
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

int cache[5000];
vector<int> seat;
vector<bool> changed;

int moveArmchair(int cur, int dist) {
	// Base case: Return when you get to the end of the seat vector.
	if (cur == seat.size()) return dist;

	int& ret = cache[i];
	if (ret != -1) return ret;

	ret = 0;
	// Task piece: Move one occupied seat to one that's empty.
	for (int i = cur; i < seat.size(); ++i) {
		if (seat[i] == 1 && !changed[i]) {
			for (int j = 0; j < seat.size(); ++j) {
				if (seat[j] == 0 && !changed[j]) {
					seat[j] = 1; changed[j] = true;
					seat[i] = 0; changed[i] = true;
					ret += abs(i - j);

					ret += min(ret, moveArmchair(cur + 1, dist);

					seat[j] = 0; changed[j] = false;
					seat[i] = 1; changed[i] = false;
					ret -= abs(i - j);
				}
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	vector<int> seat(n, 0);

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; ++i) cin >> seat[i];
	for (int i = 0; i < n; ++i) changed.PB(false);

	cout << moveArmchair(seat) << NL;

	return 0;
}

//	g++ -std=c++11 -Wall Armchairs.cpp -o Armchairs
