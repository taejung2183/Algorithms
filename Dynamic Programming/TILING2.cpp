#include <bits/stdc++.h>

#define INF 987654321
#define PB push_back
#define MP make_pair
#define NL "\n"
#define F first
#define S second 

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int MOD = 1000000007;
int cache[101];
int tiling(int n) {
	if (n <= 1) return 1;

	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (tiling(n - 2) + tiling(n - 1)) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	int C; cin >> C;
	vi answers;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		int n; cin >> n;
		answers.PB(tiling(n));
	}
	for (auto& e: answers) cout << e << NL;

	return 0;
}

//	g++ -std=c++11 -Wall TILING2.cpp -o TILING2 
