#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
	int check, total = brown + yellow;
	vector<int> ans(2);

	for (int h = 3; h <= total / 2; ++h) {
		if (total % h != 0) continue;
		int w = total / h;
		if ((check = (w - 2) * (h - 2)) == yellow) {
			ans[0] = w; ans[1] = h;
			return ans;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	if (argc < 3) { cout << "ERROR" << endl; return -1;}

	vector<int> answers = solution(stoi(argv[1]), stoi(argv[2]));
	cout << answers[0] << " " << answers[1] << endl;

	return 0;
}
