#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
const int INF = 987654321;

/*
How to solve? 

Try out all the  possible sequences with cards
since there's at most 6 cards.

In the worst case, if there are all 6 cards in the board
you only need to check 6! numbers of sequences.
*/
int[] findClosest(int r, int c, int target) {
	int coord[2];

	return coord;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;
	set<int> s;
	vector<int> cardSeq; // Hold sequences of cards

	// Check the kind of card in the board
	for (auto& row: board) for (auto& e: row) if (e != 0) s.insert(e);
	// Copy to a vector for permuatation
	cardSeq = vector<int>(s.begin(), s.end());
	
	do {
		int cnt = INF; // Count key press

		// Calculate the distance between (r,c) to the nearest cardSeq[i] card
		for (int i = 0; i < cardSeq.size(); ++i) {
			// findClosest returns coordinate for the closest cardSeq[i] card
			int closest[2] = findClosest(r, c, cardSeq[i]);

			// Check if src == dst 
			if (r == closest[0] && c == closest[1]) {
				// Press enter
				cnt += 1;
			}
			/*
			   (0,0) -> (3,3)
			   1 0 0 3
			   2 0 0 0
			   0 0 0 2
			   3 0 0 1

			   How can you know that you can ctrl -> at the beginning?
			   When you move programmatically you actually always move by one step at a time.
			   Along the way, if there were no other elements, you can count 
			   the whole way to just 1 step since you could do it with ctrl.
			 */
			// Check if the dst is on the same row or column
			else if (r == closest[0]) { // On the same row 
				// On the right side
				if (c < closest[1]) { 

				}
				// On the left side 
				else {

				}
			}
			else if (c == closest[1]) { // On the same column
				// On the upper side 
				if (r < closest[0]) {

				}
				// On the lower side
				else {

				}
			}
			else {

			}

			// Look for the match
			int match[2] = findClosest(r, c, cardSeq[i]);
		} 
		answer = min(answer, cnt);
	} while (next_permutation(cardSeq.begin(), cardSeq.end()));

    return answer;
}

int main() {
	vector<vector<int>> board = {
		{1,0,0,3},
		{2,0,0,0},
		{0,0,0,2},
		{3,0,1,0}
	};
	int r = 1, c = 0;
	cout << solution(board, r, c) << '\n';
	return 0;
}

/*
g++ -std=c++11 -Wall 카드짝맞추기.cpp
*/
