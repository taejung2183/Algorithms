#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Convert HH:MM:SS format to seconds
int toSecond(const string& time) {
	int h = stoi(time.substr(0,2));
	int m = stoi(time.substr(3,2));
	int s = stoi(time.substr(6,2));
	return h * 3600 + m * 60 + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
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
