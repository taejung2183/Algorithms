#include <bits/stdc++.h>

using namespace std;

// Pseudo code of greedy algorithm.
//int order(const vector<int>& russian, const vector<int>& korean) {
//	int wins = 0;
//	multiset<int> ratings(korean.begin(), korean.end());
//	for (int r = 0; r < russian.size(); ++r) {
//		int lowest = INF;
//		int lowIdx;
//		for (int k = 0; k < korean.size(); ++k) {
//			if (russian[r] < korean[k] && lowest > korean[k]) 
//				lowIdx = k;
//		}
//		// If you can win, use the lowest among those who can win.
//		if (lowest != INF) {
//			ratings.erase(lowIdx);
//			++wins;
//		}
//		// If you can't win, use the lowest in the entire team.
//		else {
//			ratings.erase(ratings.begin());
//		}
//	}
//
//	return wins
//}

int order(const vector<int>& russian, const vector<int>& korean) {
	int n = russian.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end());
	for (int rus = 0; rus < n; ++rus) {
		// rbegin() points the highest element.
		if (*ratings.rbegin() < russian[rus])
			// Use the lowest rating since you can't win anyway.
			ratings.erase(ratings.begin());
		else {
			// Use the lowest rating among those who can win.
			ratings.erase(ratings.lower_bound(russian[rus]));
			++wins;
		}
	}
	return wins;
}

int main() {
	vector<int> russian = {3000,2700,2800,2200,2500,1900};
	vector<int> korean = {2800,2750,29950,1800,2600,2000};

	cout << "Maximum wins: " << order(russian, korean) << '\n';

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
   1)상대를 이기는 선수 중 가장 낮은 레이팅의 선수 대신 다른 선수를 출전시키는 최적해가 있다고 가정.
   다른 선수와 가장 낮은 레이팅 선수의 출전 순서를 바꿔보면
   가장 낮은 레이팅의 선수가 하는 게임은 어차피 이긴다. (이기는 선수 중 가장 낮은 레이팅의 선수이므로)
   다른 선수가 하게 되는 게임으로 인해 승수가 낮아지는 일은 없다. (원래 선수보다 레이팅이 높은 선수가 출전)
   따러서, 상대를 이기는 선수 중 가장 낮은 레이팅의 선수를 출전시키는 최적해가 존재한다.
   2)이길 수 있는 선수가 없을 때 가장 레이팅이 낮은 선수 대신 다른 선수를 출전시키는
   최적해가 있다고 가정.
   다른 선수와 가장 레이팅이 낮은 선수의 출전 순서를 바꿔보면
   어차피 가장 낮은 선수가 하게 되는 게임은 지는 것이고 , 다른 선수가 하는 게임으로 인해 승수가 낮아지는
   일은 없다. (원래 선수보다 레이팅이 높은 선수가 출전하므로)
   따라서, 이길 수 없는 선수에게 가장 낮은 레이팅의 선수를 출전시키는 최적해가 존재한다.
   */

// g++ -std=c++11 -Wall matchOrder.cpp -o matchOrder
