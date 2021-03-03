#include <iostream>
#include <vector>
using namespace std;

#define MAX_STUDENT_NUM 10
int numOfStudents;
bool weAreFriends[MAX_STUDENT_NUM][MAX_STUDENT_NUM];

int picnic(bool isPaired[MAX_STUDENT_NUM]) {
	// Base case: If the elements within the number of numOfStudents in isPaired array are true, return 1.
	int veryFront = -1;
	for (int i = 0; i < numOfStudents; ++i) {
		if (isPaired[i] == false) {
			veryFront = i;
			break;
		}
	}
	if (veryFront == -1) return 1;

	int ret = 0;
	// Task piece: Pick two students from the list whose friend each other if they're not picked yet.	
	for (int i = veryFront + 1; i < numOfStudents; ++i) {
		if (isPaired[i] == false && weAreFriends[veryFront][i]) {
			isPaired[veryFront] = isPaired[i] = true;
			ret += picnic(isPaired);
			isPaired[veryFront] = isPaired[i] = false;
		}
	}

	return ret;
}

int main() {
	int C; cin >> C;
	int numOfPairs;
	bool isPaired[MAX_STUDENT_NUM];
	vector<int> answers;

	while(C-- > 0) {
		cin >> numOfStudents >> numOfPairs;

		for (auto& e: isPaired) e = false;
		for (int i = 0; i < MAX_STUDENT_NUM; ++i) 
			for (auto& e: weAreFriends[i]) e = false;

		for (int i = 0; i < numOfPairs; ++i) {
			int f1, f2; cin >> f1 >> f2;
			weAreFriends[f1][f2] = weAreFriends[f2][f1] = true;
		}
		answers.push_back(picnic(isPaired));
	}

	for (auto e: answers) cout << e << " ";
	cout << endl;

	return 0;
}
