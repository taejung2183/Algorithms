#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;
unordered_map<string, vector<int>> groups;
j
//for (int i = 0; i < 16; ++i) {
//	insert(key, i, point);
//}
//void insert(string* key, int mask, int point) {
//    string s = "";
//    for (int i = 0; i < 4; i++) {
//        s += (mask & (1 << i)) ? "-" : key[i];
//        map[s].push_back(point);
//    }
//}

// Make 16 possible candidates with '-'
void makeGroup(string* spec, int score) {
	string specAndBar[4][2] = { 
		{spec[0], "-"},
		{spec[1], "-"},
		{spec[2], "-"},
		{spec[3], "-"},
	};
	string str[4];
	vector<int> v1, v2 = {0,0,0,0};
	
	// Add original spec strings to the map
	for (int i = 0; i < 4; ++i) str[i] = specAndBar[i][v2[i]];
	groups[str[0]+str[1]+str[2]+str[3]].push_back(score);

	// Add spec strings with '-' to the map
	for (int i = 3; i >= 0; --i) {
		v1 = v2; v1[i] = 1; v2 = v1;
		do {
			for (int j = 0; j < 4; ++j) str[j] = specAndBar[j][v1[j]];
			groups[str[0]+str[1]+str[2]+str[3]].push_back(score);
		} while (next_permutation(v1.begin(), v1.end()));
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
	string str[4]; int score;
    
    for (int i = 0; i < info.size(); ++i) {
        istringstream ss(info[i]);
		ss >> str[0] >> str[1] >> str[2] >> str[3] >> score;
		makeGroup(str, score);
	}
	// Sort each score vector for binary search
	for (auto& e: groups) sort(e.second.begin(), e.second.end());

	// Query all the qualified candidates from the map
	string dummy; vector<int> queried;
	for (int i = 0; i < query.size(); ++i) {
        istringstream ss(query[i]);
		ss >> str[0] >> dummy >> str[1] >> dummy >> str[2] >> dummy >> str[3] >> score;

		// Get the scores of queried candidates
		queried = groups[str[0]+str[1]+str[2]+str[3]];

		// At first, I did my sorting here with queried vector and failed the efficiency test.
		// If you sort copied vector here, you might be sorting the same vector that you've already done before.
		// After I move the sorting outside of the iteration so that I can sort the original vector from the map,
		// I got passed the efficiency test.
		
		// Calcualte how many candidates with the score over "score variable"
		auto lowerBound = lower_bound(queried.begin(), queried.end(), score);
		answer.push_back(queried.size() - (lowerBound - queried.begin()));
	}

    return answer;
}

int main() {
	vector<string> info = {
		"java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50"
	};
	vector<string> query = {
		"java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150"
	};
	vector<int> answer = solution(info, query);
	for (auto& e: answer) cout << e << " "; cout << '\n';
	return 0;
}

// g++ -std=c++11 -Wall 순위검색2.cpp
