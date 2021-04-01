#include <iostream>
using namespace std;

int solution(int N) {
	int ans = 0;

	while (N > 0) {
		if (N % 2 == 0) {
			N /= 2;
		} else {
			N -= 1;
			ans += 1;
		}
	}

	return ans;
}

int main(int argc, char* argv[]) {
	cout << solution(stoi(argv[1])) << endl;
	return 0;
}
