#include <iostream>
#include <string>
using namespace std;

string numList[10] = {
	"zero","one","two","three","four","five",
	"six","seven","eight","nine"
};

char compare(string& s) {
	for (int i = 0; i < 10; ++i) 
		if (s.compare(numList[i]) == 0) return i + '0';
	return -1;
}

int solution(string s) {
    int answer = 0;
    string tmp = "";
	string ans = "";
    
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
			ans += s[i];
        }
		else {
			tmp += s[i];
			char c;
			if ((c = compare(tmp)) > -1) {
				ans += c;
				tmp.clear();
			}
		}
    }

	answer = stoi(ans);
    return answer;
}

int main(int argc, char* argv[]) {
	cout << solution(argv[1]) << endl;
	return 0;
}


