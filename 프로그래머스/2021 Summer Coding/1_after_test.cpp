#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> solution(string code, string day, vector<string> data) {
    vector<int> ans;
	map<string, string> timeAndPrice;

	string time, price;
	for (int i = 0; i < data.size(); ++i) {
		int codeIdx = data[i].find("code") + 5;

		if (code.compare(data[i].substr(codeIdx, 6)) == 0 &&
					day.compare(data[i].substr(codeIdx + 12, 8)) == 0) {
			time = data[i].substr(codeIdx + 20, 2);
			price = data[i].substr(6, codeIdx - 7 - 5);
			timeAndPrice[time] = price;
		}
	}

	for (auto e: timeAndPrice) ans.push_back(stoi(e.second));

    return ans;
}

int main() {
	vector<string> data = {
		{"price=80 code=987654 time=2019062113"},
		{"price=90 code=012345 time=2019062014"},
		{"price=120 code=987654 time=2019062010"},
		{"price=110 code=012345 time=2019062009"},
		{"price=95 code=012345 time=2019062111"},
	};
	vector<int> answers = solution("012345", "20190620", data);
	for (auto& e: answers) cout << e << endl;
	return 0;
}
