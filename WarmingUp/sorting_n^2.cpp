#include<iostream>
#include<vector>
#include <ctime>
using namespace std;

void printVector(vector<int>& v){
	for(auto e : v) cout << e << " ";
}

void swapVectorElement(vector<int>& v, int idx1, int idx2){
	int tmp = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = tmp;
}

void bubbleSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; ++i) {
		for (int j = 0; j < v.size() - (i + 1); ++j) 
			if (v[j + 1] < v[j]) swapVectorElement(v, j, j+1);
	}
}

void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size(); ++i) {
		int minIndex = i;
		for (int j = i + 1; j < v.size(); ++j) 
			if (v[j] < v[minIndex]) minIndex = j;
		swapVectorElement(v, i, minIndex);
	}
}

// Insertion sort is the fastest sorting algorithm
// in average among the O(n^2) sorting algorithms.
// Bubble and selection sorting iterates all the elements
// no matter how the input array looks like. 
void insertionSort(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) 
		for (int j = i; j > 0; --j) {
			if (v[j - 1] < v[j]) break;
			swapVectorElement(v, j - 1, j);
		}
}

int main(){
	int len; cout << "Input length: "; cin >> len;
	vector<int> ori(len, 0); for (auto& e: ori) cin >> e;
	vector<int> v; for (const auto& e: ori) v.push_back(e);
	clock_t start, end;

	start = clock();
	cout << "bubble sort : "; bubbleSort(v);
	end = clock();
	printVector(v);
	cout << "\nExecution time: ";
	printf("%lf\n\n", (double)(end - start)/CLOCKS_PER_SEC);

	for (int i = 0; i < ori.size(); ++i) v[i] = ori[i];
	start = clock();
	cout << "selection sort : "; selectionSort(v);
	end = clock();
	printVector(v);
	cout << "\nExecution time: ";
	printf("%lf\n\n", (double)(end - start)/CLOCKS_PER_SEC);

	for (int i = 0; i < ori.size(); ++i) v[i] = ori[i];
	start = clock();
	cout << "insertion sort : "; insertionSort(v);
	end = clock();
	printVector(v);
	cout << "\nExecution time: ";
	printf("%lf\n\n", (double)(end - start)/CLOCKS_PER_SEC);

	return 0;
}
