#include <bits/stdc++.h>

#define INF 987654321
#define pb push_back
#define nl "\n"

typedef long long ll;

using namespace std;

vector<bool> changed;

int moveArmchair(vector<int> seat) {
	int ret = 0;
	for (int i = 0; i < seat.size(); ++i) {
		// Seat i need to be moved.
		if (seat[i] == 1 && !changed[i]) {
			// Starting from i toward both left and right.
			int t1 = INF, t2 = INF;

			// Left side.
			int l = i - 1;
			while (l >= 0) {
				if (seat[l] == 0 && changed[l] != true) {
					t1 = abs(i - l);
					break;
				} else --l;
			}

			// Right side.
			int r = i + 1;
			while (r < seat.size()) {
				if (seat[r] == 0 && changed[r] != true) {
					t2 = abs(i - r);
					break;
				} else ++r;
			}
			
			seat[i] = 0; changed[i] = true;
			if(t1 > t2) { seat[r] = 1; changed[r] = true; ret += t2; }
			else { seat[l] = 1; changed[l] = true; ret += t1; }
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; cin >> n;
	vector<int> seat(n, 0);

	for (int i = 0; i < n; ++i) cin >> seat[i];
	for (int i = 0; i < n; ++i) changed.pb(false);

	cout << moveArmchair(seat) << nl;

	return 0;
}

//	g++ -std=c++11 -Wall Armchairs.cpp -o Armchairs
