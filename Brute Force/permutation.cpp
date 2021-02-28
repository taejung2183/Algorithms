#include <iostream>
#include <vector>
using namespace std;

void printPermutation(vector<int>& v, vector<bool>& taken, vector<int>& answer) {
	// Base case: If all the elements were taken, print.
	bool finish = true;
	for (const auto& e: taken) if (e == false) finish = false;

	if (finish == true) {
		for (const auto& e: answer) cout << e << " ";
		cout << endl;
		return;
	}

	//Task piece: Pick one element from vector which is not taken yet.
	for (int i = 0; i < v.size(); ++i) {
		if (taken[i] == true) continue;
		taken[i] = true;
		answer.push_back(v[i]);
		printPermutation(v, taken, answer);
		taken[i] = false;
		answer.pop_back();
	}
}

int main() {
	vector<int> v = {1, 2, 3, 4};
	vector<bool> taken;
	vector<int> answer;
	
	for (int i = 0; i < v.size(); ++i) 
		taken.push_back(false);

	printPermutation(v, taken, answer);

	return 0;
}
