#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
using namespace std;

bool isPrimeNumber(string number) {
	int num = stoi(number);

	if (num <= 1) return false;
	for (int i = 2; i <= sqrt(num); ++i) 
		if (num % i == 0) return false;
	return true;
}

int makePrimeNumber(string numbers, string candidate, vector<string>& answers) {
	// If there's no number left to pick, return the number of answers.
	if (numbers.length() == 0) return answers.size();

	int ret = 0;
	char number;
	// Task piece: Pick one number from the string and concat to the current candidate. 
	for (int i = 0; i < numbers.length(); ++i) {
		number = numbers[i];
		candidate.append(1, number);
		numbers.erase(i, 1);

		if (isPrimeNumber(candidate) == true) {
			bool isNew = true;
			for (int i = 0; i < answers.size(); ++i) {
				if (stoi(candidate) == stoi(answers[i])) {
					isNew = false;
					break;
				}
			}
			if (isNew == true) answers.push_back(candidate);
		}

		ret = makePrimeNumber(numbers, candidate, answers);
		candidate.pop_back();
		numbers.insert(i, 1, number);
	}

	return ret;
}

/*
int makePrimeNumber(string numbers, string candidate, set<int>& answers) {
	cout << "numbers: " << numbers << endl;
	cout << "candidate: " << candidate << endl;
	cout << "answers: "; for (const auto& e: answers) cout << e << " "; cout << endl;
	// If there's no number left, return the number of answers.
	if (numbers.length() == 0) {
		cout << "Returning: " << answers.size() << endl;
		cout << "answers: "; for (const auto& e: answers) cout << e << " "; cout << endl;
		return answers.size();
	}

	int ret = 0;
	char number;
	// Task piece: Pick one number from the string and concat to the current candidate. 
	for (int i = 0; i < numbers.length(); ++i) {
		number = numbers[i];
		candidate.append(1, number);
		numbers.erase(i, 1);
		if (isPrimeNumber(candidate) == true) 
			answers.insert(stoi(candidate));
		cout << endl;
		ret = makePrimeNumber(numbers, candidate, answers);
		candidate.pop_back();
		numbers.insert(i, 1, number);
	}
	return ret;
}
*/

int solution(string numbers) {
	int ret;
	string candidate = "";
	vector<string> answers;
	//set<int> answers;
	ret = makePrimeNumber(numbers, candidate, answers);
	return ret;
}

int main(int argc, char* argv[]) {
	cout << solution(argv[1]) << endl;
	return 0;
}
