#include <bits/stdc++.h>
using namespace std;

void printPicked(vector<int>& picked){

	for(int i=0; i<picked.size(); ++i){
		cout << picked[i] << " ";
	} cout << endl;
}

// n�� �� m�� ����.(0~n������ �ڿ���) 
void comb1(int len, int remain , vector<int>& picked){

	if(remain == 0){
		printPicked(picked);
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1; 

	for(int i=smallest; i<len; ++i){
		picked.push_back(i);
		comb1(len, remain - 1, picked);
		picked.pop_back();
	}
}

// �迭�� �־����� m�� ����.
 void comb2(vector<int> arr, int remain, vector<int>& picked){

	if(remain == 0){
		printPicked(picked);
		return;
	}

	int smallest = picked.empty() ? 0 : (find(arr.begin(), arr.end(), picked.back()) - arr.begin()) + 1; 

	for(int i=smallest; i<arr.size(); ++i){
		picked.push_back(arr[i]);
		comb2(arr, remain - 1, picked);
		picked.pop_back();
	}
}

int main(){

	/* 
	int n, m;
	vector<int> picked;

	cin >> n >> m;
	comb(n, m, picked);
	*/

	int len;
	int m;
	vector<int> arr;
	vector<int> picked;

	cin >> len;
	while(len-- > 0){
		int n;
		cin >> n;
		arr.push_back(n);
	}
	cin >> m;

	comb2(arr, m, picked);


	return 0;
}
