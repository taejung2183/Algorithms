#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<int> ori;
vector<int> arr;

void swap(int a, int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

// This is very slow implementation.
void quickSort_first_try(int lo, int hi) {
	if (hi < lo) return;

	int first = lo, last = hi, pivotItem = arr[lo];
	vector<int> tmp(arr.size(), 0);

	for (int i = lo + 1; i <= hi; ++i) {
		if (arr[i] < pivotItem) {
			tmp[first] = arr[i];
			++first;
		} else {
			tmp[last] = arr[i];
			--last;
		}
	}
	tmp[first] = pivotItem;

	for (int i = lo; i <= hi; ++i) arr[i] = tmp[i];

	quickSort_first_try(lo, first - 1);
	quickSort_first_try(first + 1, hi);
}

void quickSort1(int lo, int hi) {
	if (hi <= lo) return;

	int pivotItem = arr[lo], head = lo; 

	for (int i = lo + 1; i <= hi; ++i) {
		// Whenever you find an element smaller than the pivot item,
		// store that element from the very first index (except pivot index.)
		// while pushing it back one by one. (Updating head variable.)
		if (arr[i] < pivotItem) {
			++head;
			swap(i, head);
		}
	}
	swap(lo, head);

	quickSort1(lo, head - 1);
	quickSort1(head + 1, hi);
}

void quickSort2(int lo, int hi) {
	if (hi <= lo) return;

	int pivotItem = arr[lo];
	int head = lo + 1, tail = hi;

	while (head < tail) {
		while (arr[head] < pivotItem && head < hi) ++head;
		while (pivotItem < arr[tail]) --tail;

		if (head < tail) swap(head, tail);
		else swap(lo, tail);
	}

	quickSort2(lo, tail - 1);
	quickSort2(tail + 1, hi);
}

int main() {
	int len; cout << "Input length: "; cin >> len;

	for (int i = 0; i < len; ++i) {
		int n; cin >> n;
		ori.push_back(n);
	}

	for (int i = 0; i < len; ++i) 
		arr.push_back(ori[i]);

	clock_t start = clock();
	quickSort_first_try(0, arr.size() - 1);
	clock_t end = clock();
	cout << "quickSort_first_try" << endl;
	cout << "After sort: ";
	for (const auto& e: arr) cout << e << " ";
	cout << "\nExecution time: ";
	printf("%lf\n", (double)(end - start)/CLOCKS_PER_SEC);

	// Reset the array.
	for (int i = 0; i < len; ++i) arr[i] = ori[i];

	// Testing quickSort1.
	clock_t start_quickSort1 = clock();
	quickSort1(0, arr.size() - 1);
	clock_t end_quickSort1 = clock();
	cout << "quickSort1" << endl;
	cout << "After sort: ";
	for (const auto& e: arr) cout << e << " ";
	cout << "\nExecution time: ";
	printf("%lf\n", (double)(end_quickSort1 - start_quickSort1)/CLOCKS_PER_SEC);

	// Reset the array.
	for (int i = 0; i < len; ++i) arr[i] = ori[i];

	// Testing quickSort2.
	clock_t start_quickSort2 = clock();
	quickSort2(0, arr.size() - 1);
	clock_t end_quickSort2 = clock();
	cout << "quickSort2" << endl;
	cout << "After sort: ";
	for (const auto& e: arr) cout << e << " ";
	cout << "\nExecution time: ";
	printf("%lf\n", (double)(end_quickSort2 - start_quickSort2)/CLOCKS_PER_SEC);

	return 0;
}
