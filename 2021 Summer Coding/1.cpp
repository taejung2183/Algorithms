#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(string code, string day, vector<string> data) {
    vector<int> ans;
	vector<vector<int>> tmp;

	for (int i = 0; i < data.size(); ++i) {
		int idx = 0;
		for (int j = 0; j < data[i].size(); ++j) {
			if (data[i][j] == ' ') {
				idx = j + 6; 
				break;
			}
		}

		vector<int> row;
		if (code.compare(data[i].substr(idx, 6)) == 0 &&
				day.compare(data[i].substr(idx + 12, 8)) == 0) {
			int date = stoi(data[i].substr(idx + 20, 2));
			int price = stoi(data[i].substr(6, idx - 7));
			row.push_back(date);
			row.push_back(price);
			tmp.push_back(row);
			row.clear();
		}
	}

	int len = tmp.size();
	for (int j = 0; j < len; ++j) {
		int minIdx = 0;
		for (int i = 1; i < tmp.size(); ++i) {
			if (tmp[i][0] < tmp[minIdx][0]) minIdx = i;
		}
		ans.push_back(tmp[minIdx][1]);
		tmp.erase(tmp.begin() + minIdx);
	}

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
