#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int toSecond(const string& time) {
	int ret = 0;
	// 01:20:15
	istringstream ss(time);
	string timeStr;

	while (getline(ss, timeStr, ':')) {
		cout << timeStr << '\n';
	}

	return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
	toSecond(play_time);
    return answer;
}

int main() {
	string play_time = "02:03:55";
	string adv_time = "00:14:15";
	vector<string> logs = {
		{"01:20:15-01:45:14"},
		{"00:40:31-01:00:00"},
		{"00:25:50-00:48:29"},
		{"01:30:59-01:53:29"},
		{"01:37:44-02:02:30"},
	};
	cout << solution(play_time, adv_time, logs) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 광고삽입.cpp
 */
