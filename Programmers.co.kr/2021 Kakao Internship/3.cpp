#include <iostream>
#include <vector>
#include <string>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
	vector<int> deleted;
	for (int i = 0; i < n; ++i) answer += 'O';

	for (int i = 0; i < cmd.size(); ++i) {
			char& cur = cmd[i][0];
			if (cur == 'D') {
				int stride = cmd[i][2]-'0';
				for (int step = 0; step < stride; ++step) {
					int s = 1;
					while (answer[k + s] == 'X') ++s;
					k += s;
				}
			}
			else if (cur == 'U') {
				int stride = cmd[i][2]-'0';
				for (int step = 0; step < stride; ++step) {
					int s = -1;
					while (answer[k + s] == 'X') --s;
					k += s;
				}
			}
			else if (cur == 'C') {
				// Delete.
				answer[k] = 'X';
				deleted.push_back(k);
				// Update cursor.
				int s = 1;
				while (answer[k + s] == 'X') ++s;
				// answer[k + s] == 'O'
				if (k + s < n) k += s;
				// k+s is out of range.
				else {
					int s = -1;
					while (answer[k + s] == 'X') --s;
					k += s;
				}
			}
			else { // cur == 'Z'
				int z = deleted.back();
				deleted.pop_back();
				answer[z] = 'O';
			}
	}

    return answer;
}

string solution(int n, int k, vector<string> cmd) {
	vector<int> deleted;
	string answer = "";
	
	for (int i = 0; i < n; ++i) answer += (i + '0');
	// 이렇게 할 수 있으꺼 같은데요? 
	// 삭제되는 번호를 제외한 substr으로 재귀하면 마지막에 남은 번호 만 'O'
}

int main(int argc, char* argv[]) {
	vector<string> cmd1 = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
	vector<string> cmd2 = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
	cout << solution(8, 2, cmd1) << endl;
	cout << solution(8, 2, cmd2) << endl;
	return 0;
}
