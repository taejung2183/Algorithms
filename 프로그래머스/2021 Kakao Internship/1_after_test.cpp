#include <iostream>
#include <string>
using namespace std;

const string numList[10] = {
	"zero","one","two","three","four","five",
	"six","seven","eight","nine"
};

int solution(string s) {
    int answer = 0;
    
	bool exist;
	for (int i = 0; i < 10; ++i) {
		int pos = s.find(numList[i]);
		if (pos != string::npos) {
			s.replace(pos, numList[i].length(), 1, i + '0');
			--i;
		}
	}
	
    return answer = stoi(s);
}

int main(int argc, char* argv[]) {
	string s1 = "four1twoseven3eightfourtwo";
	string s2 = "five8zeroninethree";

	cout << solution(s1) << endl;
	cout << solution(s2) << endl;

	return 0;
}

