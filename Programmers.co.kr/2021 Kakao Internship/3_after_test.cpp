#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> deleted;
string processCMD(int k, string nums, string cmd) {
	// Base case: If there's no more command, return.
	if (cmd.empty()) return nums;
	
	char curCMD = cmd[0];
	
	if (curCMD == 'D') {
		k += cmd[2] - '0';
		cmd.erase(0, 2);
	}
	else if (curCMD == 'U') {
		k -= cmd[2] - '0';
		cmd.erase(0, 2);
	}
	else if (curCMD == 'C') {
		deleted.push_back(nums[k]);
		nums.erase(k, 1);
		if (k == nums.length()) --k;
	}
	else { // curCMD == 'Z'
		char z = deleted.back();
		deleted.pop_back();

		int len = nums.length();
		for (int i = 0; i < len; ++i) 
			if (z < nums[i]) { 
				nums.insert(i, 1, z); 
				if (i < k) --k;
				break; 
			}
		if (len == nums.length()) nums.push_back(z);
	}
	cmd.erase(0, 1);

	string ret = processCMD(k, nums, cmd);
	return ret;
}

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	string nums = "";
	string strCMD = "";
	
	for (int i = 0; i < n; ++i) nums += (i + '0');
	for (int i = 0; i < cmd.size(); ++i) strCMD += cmd[i];

	answer = processCMD(k, nums, strCMD);
	cout << answer << endl;

	for (int i = 0; i < n; ++i) {
		if (answer[i] != i + '0') 
			answer.insert(i, 1, 'X');
		else answer[i] = 'O';
	}

	return answer;
}

int main(int argc, char* argv[]) {
	vector<string> cmd1 = {"D 2","C","U 3","C","D 4","C","U 2","C","Z","Z"};
	vector<string> cmd2 = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
	cout << solution(8, 2, cmd1) << endl;
	cout << solution(8, 2, cmd2) << endl;
	return 0;
}

