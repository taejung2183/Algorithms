#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

void merge(int lo, int mid, int hi) {
	// Task piece: Compare the elements and set the order.
	int i = lo, j = mid + 1, k = lo;
	vector<int> tmp(arr.size(), 0);

	while (i <= mid && j <= hi) {
		if (arr[i] < arr[j]) { tmp[k] = arr[i]; ++i; }
		else { tmp[k] = arr[j]; ++j; } 
		++k;
	}

	// Copy the leftover.
	if (mid < i) {
		for (int l = j; l <= hi; ++l) tmp[k++] = arr[l];
	} else { // hi < j
		for (int l = i; l <= mid; ++l) tmp[k++] = arr[l];
	}

	// Update the original array with the temporary array which is set in order.
	for (int l = lo; l <= hi; ++l) arr[l] = tmp[l];
}

void divide(int lo, int hi) {
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		divide(lo, mid);
		divide(mid + 1, hi);
		merge(lo, mid, hi); 
	}
}

int main() {
	int len; cout << "Input length: "; cin >> len;
	
	for (int i = 0; i < len; ++i) {
		int n; cin >> n;
		arr.push_back(n);
	}

	divide(0, arr.size() - 1);
	cout << "After sort: ";
	for (const auto& e: arr) cout << e << " ";
	cout << endl;
			
	return 0;
}

