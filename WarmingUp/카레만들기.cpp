#include <iostream>
using namespace std;
int main() {
	int potato = 2, carrot = 1, onion = 3;
	int ourPotato = 20, ourCarrot = 9, ourOnion = 22;

	int p = ourPotato / potato, c = ourCarrot / carrot, o = ourOnion / onion;
	cout << (p > c ? min(c,o) : min(p,o)) << " 인분의 카레를 만들 수 있어요!" << '\n';

	return 0;
}
