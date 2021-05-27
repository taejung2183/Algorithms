#include <bits/stdc++.h>

using namespace std;

int order(cost vector<int>& russian, const vector<int>& korean) {
	int n = russian.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end());
	for (int rus = 0; rus < n; ++rus) {
		if (*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin());
		else {
			ratings.erase(ratings.lower_bound(russian[rus]));
			++wins;
		}
	}
	return wins;
}

int main() {

	return 0;
}
/*
   // 탐욕적인 방법을 생각해보기.

   1.매 단계에서 가장 높은 레이팅의 선수를 출전시킴
   3000 2700 2800 2200 2500 1900
   2995 2800 2750 2600 2000 1800  승수: 2

   2.매 단계에서 상대 선수 레이팅과 가장 가깝게 높은 선수를 출전
   3000 2700 2800 2200 2500 1900
   2995 2750 2800 2600 2000 1800  승수: 3

   3.매 단계에서 상대 레이팅과 가장 가깝게 이기되 이길 수 없는 상대는 가장 낮은 레이팅의 선수를 출전 시킴
   3000 2700 2800 2200 2500 1900
   1800 2750 2800 2600 2995 2000  승수: 5 (최다승)

   3번의 탐욕적 선택 속성 증명
   1)이길 수 있는 선수가 없을 때 가장 레이팅이 낮은 선수 대신 다른 선수를 출전시키는
   최적해가 있다고 가정.
   다른 선수와 가장 레이팅이 낮은 선수의 출전 순서를 바꿔보면
   어차피 가장 레이팅이 낮은 선수의 게임은 지는 것이고, 다른 선수가 하는 게임은
   원래 게임보다 
   */

// g++ std=c++11 -Wall matchOrder.cpp -o matchOrder
