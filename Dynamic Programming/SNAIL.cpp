#include <bits/stdc++.h>

using namespace std;

int n, m;
int cache[100][201];

int climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;

	int& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
}

double climb(int n, int m) {
	int possible = 0;
	double totalComb = pow(2, m);

	vector<int> v;
	int two = 0; 
	while (two <= m) {
		for (int i = 0; i < m - two; ++i) v.push_back(1);
		for (int i = 0; i < two; ++i) v.push_back(2);

		int sum = 0;
		for (auto& e: v) sum += e; 
		if (sum >= n) ++possible;

		++two;
		v.clear();
	}

	return possible / totalComb;
}

int main() {
	int n, m;
	cin >> n >> m;

	cout << climb(n, m) << '\n';

	return 0;
}
/*
   거리: n미터
   맑은 날: 2미터
   비온 날: 1미터
   시간: m일
   각 날에 비 올 확률: 50%

   전체 조합의 수 = 2^m
   m = 2 
   1 1 / 1 2 / 2 1 / 2 2 

   m = ?
   - - - - / 

   완전 탐색: 주어진 m에 대해 길이 m을 1과 2 로 만들 수 있는 모든 조합의 합을
   계산하여 주어진 n보다 크거나 같다면 우물 끝에 도달할 수 있음
 */

// g++ -std=c++11 -Wall SNAIL.cpp -o SNAIL
