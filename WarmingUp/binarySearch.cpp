#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v){
	for(auto e : v) cout << e << " "; cout << endl;
}

void swapVectorElement(vector<int>& v, int idx1, int idx2){
	int tmp = v[idx1];
	v[idx1] = v[idx2];
	v[idx2] = tmp;
}

//Suppose that A[-1] = -infinite , A[n] = +infinite
int binarySearch(const vector<int>& A, int x){
	int n = A.size();
	int lo = -1, hi = n;
	
	//loop in variant 1: lo < hi
	//loop in variant 2: A[lo] < x <= A[hi]
	//loop in variant is satisfied here.
	while(lo + 1 < hi){
		int mid = (lo + hi) / 2;
		if(A[mid] < x) lo = mid;
		else hi = mid;
	}
	return hi;
	//loop in variant is satisfied here as well.
}

void insertionSort(vector<int>& v){
	for(int i = 1; i < v.size(); ++i)
		for(int j = i; j > 0; --j)
			if(v[j - 1] > v[j]) swapVectorElement(v, j, j - 1);
	printVector(v);
}

int main(){
	vector<int> A = {3, 5, 2, 6, 4, 1};

	insertionSort(A);

	cout << "Input search item: ";
	int item; cin >> item;
	cout << item << " is at " << binarySearch(A, item) << endl;

	return 0;
}
