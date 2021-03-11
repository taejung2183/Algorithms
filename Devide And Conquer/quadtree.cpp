#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hand over the reference for the iterator as an argument so that
// you can retain the modifications inside of the recursion.
string reverseQuadTree(string::iterator& iter) {
	char letter = *iter; ++iter;
	// Base case: If the letter is not 'x', return the letter.
	if (letter == 'w' || letter == 'b') return string(1, letter);

	// If the letter is 'x', get into the recursion.
	// Task piece: Take one piece at the front from the quadTree string.
	string ret[4];
	ret[0] = reverseQuadTree(iter);
	ret[1] = reverseQuadTree(iter);
	ret[2] = reverseQuadTree(iter);
	ret[3] = reverseQuadTree(iter);

	return "x" + ret[2] + ret[3] + ret[0] + ret[1];
}

int main() {
	int C; cin >> C;
	string quadTree;
	vector<string> answers;

	while (C-- > 0) {
		cin >> quadTree;
		string::iterator iter = quadTree.begin();
		answers.push_back(reverseQuadTree(iter));
	}
	for (const auto& e: answers) cout << e << endl;

	return 0;
}
