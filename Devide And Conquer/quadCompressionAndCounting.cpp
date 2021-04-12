#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> cutInQuarter(vector<int> coord, vector<vector<int>> arr) {
	vector<int> row;
	vector<vector<int>> ret;
	for (int i = coord[0]; i < coord[1]; ++i) {
		for (int j = coord[2] ; j < coord[3]; ++j) 
			row.push_back(arr.at(i).at(j));
		ret.push_back(row);
		row.clear();
	}
	return ret;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0); // {0, 0}

	// Base case: If all the numbers in the arr are same, update the answer vector and return.
	int n = arr[0][0];
	bool identical = true;
	for (const auto& row: arr) {
		for (const auto& e: row) 
			if (e != n) identical = false;
	}

	if (identical == true) {
		n == 0 ? answer[0] += 1 : answer[1] += 1;
		return answer;
	}

	// Different number exists.

	// Generate sub-array for each quarter of the arr and get into recursion.
	vector<vector<int>> quarterArr;
	int len = arr.size();
	vector<int> tmp(2, 0);
	// Coordinates for cutting array. {start row, end row, start column, end column}
	vector<int> coord(4);

	// Upper left.
	coord = {0, len / 2, 0, len / 2};
	quarterArr = cutInQuarter(coord, arr);
	tmp = solution(quarterArr);
	answer[0] += tmp[0]; answer[1] += tmp[1];

	// Upper right.
	coord = {0, len / 2, len / 2, len};
	quarterArr = cutInQuarter(coord, arr);
	tmp = solution(quarterArr);
	answer[0] += tmp[0]; answer[1] += tmp[1];

	// Lower left.
	coord = {len / 2, len, 0, len / 2};
	quarterArr = cutInQuarter(coord, arr);
	tmp = solution(quarterArr);
	answer[0] += tmp[0]; answer[1] += tmp[1];

	// Lower right.
	coord = {len / 2, len, len / 2, len};
	quarterArr = cutInQuarter(coord, arr);
	tmp = solution(quarterArr);
	answer[0] += tmp[0]; answer[1] += tmp[1];

    return answer;
}

int main(int argc, char* argv[]) {
	vector<vector<int>> arr = {
		{1, 1, 0, 0},
		{1, 0, 0, 0},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
	};
	vector<int> answer = solution(arr);
	for (const auto& e: answer) cout << e << " "; cout << endl;

	return 0;
}
