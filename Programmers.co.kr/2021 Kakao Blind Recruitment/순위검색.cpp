#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(string a, string b) {
	string s1 = "", s2 = ""; 
	for (auto rit = a.rbegin(); *rit != ' '; ++rit) s1.insert(0, 1, *rit);
	for (auto rit = b.rbegin(); *rit != ' '; ++rit) s2.insert(0, 1, *rit);
	return stoi(s1) > stoi(s2);
}

vector<string> split(string str, char delimeter) {
	istringstream ss(str);
	vector<string> ret;
	string tmp;

	while (getline(ss, tmp, delimeter)) ret.push_back(tmp);
	return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

	// Sort by descending order of score
	sort(info.begin(), info.end(), cmp);

	string q, infoStr, score;
	for (int i = 0; i < query.size(); ++i) {
		q = query[i];

		// Extract score from current query
		for (auto rit = q.rbegin(); *rit != ' '; ++rit) score.insert(0, 1, *rit);
		cout << "here\n";
		// Binary search to find candidates with the score over the query's score
		int mid, lo = 0, hi = info.size() - 1;
		string tmpInfo, tmpScore;
		while (lo < hi) {
			// Get the info at the middle 
			mid = (lo + hi) / 2;
			tmpInfo = info[mid];

			// Exract score 
			for (auto rit = tmpInfo.rbegin(); *rit != ' '; ++rit) tmpScore.insert(0, 1, *rit);

			if (stoi(tmpScore) < stoi(score)) lo = mid + 1;
			else hi = mid;
		}
		cout << mid - 1 << '\n';

		// Search from mid - 1
		vector<string> infoV, queryV;
		for (int j = mid - 1; j < info.size(); ++j) {
			infoStr = info[j];
			
			infoV = split(infoStr, ' ');
			queryV = split(q, ' ');
			// Erase "and"
			queryV.erase(queryV.begin() + 1);
			queryV.erase(queryV.begin() + 3);
			queryV.erase(queryV.begin() + 5);
			queryV.erase(queryV.begin() + 7);

			for (auto& e: infoV) cout << e << " "; cout << '\n';
			for (auto& e: queryV) cout << e << " "; cout << '\n';
		}
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

// g++ -std=c++11 -Wall 순위검색.cpp
