//Pick the certain number of elements from sequential native number.
#include<iostream>
#include<vector>
using namespace std;

void printPicked(vector<int>& arr){
	for(int i=0;i<arr.size();++i){
		cout<<arr[i]<<" ";
	} cout<<endl;
}

//   Find all the combinations of picking m number of 
//   elements in the natural ordered number with length of n.
//   e.g. n = 7, m = 3 
//   array : 1 2 3 4 5 6 7
//   1 2 3, 1 2 4, 1 2 5, 1 2 6, 1 2 7 ... 
void combination(vector<int>& picked, int n, int m){
	// base case: Picking m number of elements is done.
	if (m == 0) {
		printPicked(picked);
		return; 
	}

	// Order is irrelevant. (1,2,3) == (2,1,3).  
	// Don't check those same combinations.
	// Define a variable that can force the iteration 
	// to always starts from the smallest element.
	int smallest;
	if (picked.empty()) {
		smallest = 1;
	} else {
		smallest = picked.back() + 1;
	}

	for(int i = smallest; i <= n; ++i) {
		picked.push_back(i);
		combination(picked, n, m - 1);
		picked.pop_back();
	}
}

int main(){
	int len=0;
	int remain=0;
	vector<int> arr;

	cout<<"Input total number of elements: ";
	cin>>len;
	cout<<"How much to pick?: ";
	cin>>remain;

	combination(arr, len, remain);

	return 0;
}
