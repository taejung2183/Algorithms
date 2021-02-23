#include<iostream>
#include<vector>
using namespace std;

int maximumPartialSum(vector<int> v){
	/*
	   The most inefficient algorithm(O(n^3))
	   -> Iterating all the parts of the array.
		*/
	int partialSum = 0, ret = 0;
	/*
	for(int front = 0; front < v.size(); ++front){
		for(int back = front; back < v.size(); ++back){
			for(int i = front; i <= back; ++i)
				partialSum += v[i];

			ret = max(partialSum, ret);
			partialSum = 0;
		}
	}
	*/

	/*
	   O(n^2)
	   -> Idea of moving average algorithm.
	   No repeated calculation of already summed data.
	   */
	for(int i = 0; i < v.size(); ++i){
		partialSum = 0; 
		for(int j = i; j < v.size(); ++j){
			partialSum += v[j];
			ret = max(partialSum, ret);
		}
	}

	return ret;
}

int main(){
	vector<int> v = {-7,4,-3,6,3,-8,3,4};
	cout << maximumPartialSum(v) << endl;

	return 0;
}
