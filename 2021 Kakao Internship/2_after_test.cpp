#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool distanceCheck(vector<string>& place) {
	int len = place.size();

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (place[i][j] != 'P') continue;
			// Right side.
			if (j + 1 < len && place[i][j + 1] == 'P') return false;
			if (j + 2 < len && place[i][j + 2] == 'P') 
				if (place[i][j + 1] == 'O') return false;

			// Down side.
			if (i + 1 < len && place[i + 1][j] == 'P') return false;
			if (i + 2 < len && place[i + 2][j] == 'P') 
				if (place[i][j + 1] == 'O') return false;

			// Upper diagonal.
			if (0 <= i - 1 && j + 1 < len && place[i - 1][j + 1] == 'P') 
				if (place[i - 1][j] == 'O' || place[i][j + 1] == 'O') return false;

			// Lower diagonal.
			if (i + 1 < len && j + 1 < len && place[i + 1][j + 1] == 'P') 
				if (place[i + 1][j] == 'O' || place[i][j + 1] == 'O') return false;
		}
	}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

	for (int i = 0; i < places.size(); ++i) {
		int ans = distanceCheck(places[i]) ? 1 : 0;
		answer.push_back(ans);
	}

    return answer;
}

int main(int argc, char* argv[]) {
	vector<vector<string>> testCase = {
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"},
	};

	vector<int> ans = solution(testCase);
	for (const auto& e: ans) cout << e << endl;

	return 0;
}
