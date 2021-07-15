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
	int watchCnt[max_sec];
	int playSec = toSecond(play_time);
	int advSec = toSecond(adv_time);
	
	for (auto& e: logs) {
		int start = toSecond(e.substr(0,8));
		int end = toSecond(e.substr(9,8));
		watchCnt[start] += 1;
		watchCnt[end] -= 1;
	}

	for (int i = 1; i <= max_sec; ++i) watchCnt[i] += watchCnt[i - 1];
	for (int i = 1; i <= max_sec; ++i) watchCnt[i] += watchCnt[i - 1];

	// 자료형 문제인가..? 매번 실행마다 결과가 다름
	long long ans = 0, maxPlayed = watchCnt[advSec - 1];
//	cout << "accumulated time: " << maxPlayed << " started at: " << ans <<  '\n';
	for (int i = 1; i + advSec <= playSec; ++i) {
		long long tmp = watchCnt[i + advSec - 1] - watchCnt[i - 1]; 
		if (maxPlayed < tmp) {
			maxPlayed = tmp;
			ans = i;
//			cout << "accumulated time: " << tmp << " started at: " << i <<  '\n';
		}
	}
	answer = toTimeFormat(ans);
    return answer;
}

int main() {
//	string play_time = "02:03:55";
//	string adv_time = "00:14:15";
//	vector<string> logs = {
//		"01:20:15-01:45:14",
//		"00:40:31-01:00:00",
//		"00:25:50-00:48:29",
//		"01:30:59-01:53:29",
//		"01:37:44-02:02:30",
//	};
	string play_time = "99:59:59";
	string adv_time = "25:00:00";	
	vector<string> logs = {
		"69:59:59-89:59:59", 
		"01:00:00-21:00:00", 
		"79:59:59-99:59:59", 
		"11:00:00-31:00:00"	
	};
//	string play_time = "00:00:13";
//	string adv_time = "00:00:04";	
//	vector<string> logs = {
//		"00:00:00-00:00:02",
//		"00:00:01-00:00:03",
//		"00:00:02-00:00:04",
//		"00:00:08-00:00:12",
//		"00:00:09-00:00:12",
//		"00:00:11-00:00:13",
//	};
	cout << solution(play_time, adv_time, logs) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 광고삽입.cpp
 */
