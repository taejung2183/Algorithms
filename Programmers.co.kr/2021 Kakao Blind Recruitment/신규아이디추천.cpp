#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string new_id) {
    string answer = "";

	// 1. Upper case to lower case
	for (auto& e: new_id) if (isupper(e)) e = tolower(e);

	// 2. Erase except alphabet lowercase, numbers, -, _, . 
	for (int i = 0; i < new_id.size(); ++i) {
		char& c = new_id[i];
		if (!isalpha(c) && !isdigit(c) && c != '-' && c != '_' && c != '.') {
			new_id.erase(i, 1); --i;
		}
	}

	// 3. Remove consecutive period
	for (int i = 0; i < new_id.size(); ++i) {
		char& c = new_id[i];
		if (c == '.' && new_id.size() > 1 && new_id[i + 1] == '.') {
				new_id.erase(i, 1); --i;
		}
	}

	// 4. Remove period at the first or last element
	if (new_id[0] == '.') new_id.erase(0, 1);
	if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

	// 5. Add "a" if it's blank
	if (new_id.empty()) new_id += "a";

	// 6.
	if (new_id.size() > 15) new_id = new_id.substr(0, 15);
	if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

	// 7. Too short
	if (new_id.size() < 3) while (new_id.size() < 3) { new_id += new_id[new_id.size() - 1]; }

	answer = new_id;
    return answer;
}

int main() {
	string new_id1 = "...!@BaT#*..y.abcdefghijklm";
	string new_id2 = "z-+.^.";
	string new_id3 = "=.=";
	string new_id4 = "123_.def";
	string new_id5 = "abcdefghijklmn.p";
	cout << solution(new_id1) << '\n';
	cout << solution(new_id2) << '\n';
	cout << solution(new_id3) << '\n';
	cout << solution(new_id4) << '\n';
	cout << solution(new_id5) << '\n';
}

// g++ -std=c++11 -Wall 신규아이디추천.cpp -o 신규아이디추천
