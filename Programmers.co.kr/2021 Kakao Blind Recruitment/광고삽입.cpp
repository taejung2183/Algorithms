#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
const int max_sec = 360000;

// Convert HH:MM:SS format to seconds
int toSecond(const string& time) {
	int h = stoi(time.substr(0,2));
	int m = stoi(time.substr(3,2));
	int s = stoi(time.substr(6,2));
	return h * 3600 + m * 60 + s;
}

// Convert seconds to HH:MM:SS format
string toTimeFormat(int sec) {
	int h = sec / 3600; sec %= 3600;
	int m = sec / 60; sec %= 60;
	int s = sec;
	string hh = to_string(h); if (h < 10) hh = "0" + hh;
	string mm = to_string(m); if (m < 10) mm = "0" + mm;
	string ss = to_string(s); if (s < 10) ss = "0" + ss;
	return hh + ":" + mm + ":" + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
	// Don't forget to initialize array
	long long watchCnt[max_sec] = {0, };
	int playSec = toSecond(play_time);
	int advSec = toSecond(adv_time);

	for (auto& e: logs) {
		int start = toSecond(e.substr(0,8));
		int end = toSecond(e.substr(9,8));
		watchCnt[start] += 1;
		watchCnt[end] -= 1;
	}

	for (int i = 1; i < playSec; ++i) watchCnt[i] += watchCnt[i - 1];
	for (int i = 1; i < playSec; ++i) watchCnt[i] += watchCnt[i - 1];

	long long ans = 0, maxPlayed = watchCnt[advSec - 1];
	for (int i = advSec; i < playSec; ++i) {
		long long tmp = watchCnt[i] - watchCnt[i - advSec]; 
		if (maxPlayed < tmp) {
			maxPlayed = tmp;
			ans = i - advSec + 1;
		}
	}
	answer = toTimeFormat(ans);
    return answer;
}

int main() {
	string p1 = "02:03:55";
	string ad1 = "00:14:15";
	vector<string> logs1 = {
		"01:20:15-01:45:14",
		"00:40:31-01:00:00",
		"00:25:50-00:48:29",
		"01:30:59-01:53:29",
		"01:37:44-02:02:30",
	};
	cout << solution(p1,ad1,logs1) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 광고삽입.cpp
 */
