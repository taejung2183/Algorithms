#include <iostream>
#include <ctime>
using namespace std;

// Pick r number of elements without order from n number of elements.
int bino1(int n, int r) {
	// Base case: If you have nothing to pick or have to pick all the elements, 
	// you have one case of picking elements.
	if (r == 0 || n == r) return 1;

	return bino1(n - 1, r - 1) + bino1(n - 1, r);
}

// Memoization.
int cache[100][100];
int bino2(int n, int r) {
	if (r == 0 || n == r) return 1;

	int& ret = cache[n][r];

	if (ret != -1) return ret;
	return ret = bino2(n - 1, r - 1) + bino2(n - 1, r);
}

int main() {
	// Only 0 or -1 can be initialized with memset function.
	memset(cache, -1, sizeof(cache));
	clock_t start, end;

	start = clock();
	cout << bino1(8, 4) << endl;
	end = clock();
	cout << "Time: " << end - start << endl;

	start = clock();
	cout << bino2(8, 4) << endl;
	end = clock();
	cout << "Time: " << end - start << endl;

	return 0;
}
