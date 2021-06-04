#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
-Starts from (0,0). Go straight / left turn / right turn.
-Implement complete search for every three directions at each & every cells.
-No need to take the same spot more than once.
-Cacheing the answers at each & every cells.

-This problem has Optimal substructure. (You need to choose optimized route at every sub problems.)

Recurrence relation : 

findRoute(int y, int x) : Return the smallest cost route to the end of the board with the taken vector and the current coordinate. 
(Original board and taken vectors are global variable, taken vector is for checking the cell if its already taken) 

Do I need to have a variable for current direction? (Unless, u don't know if you're heading straight or whatever)
Just go for four directions and make use of the taken vector ? (Then, how am i gonna charge for different cost between straight and corner?)

 
findRoute(int y, int x) = { findRoute(int y + 1, int x)
						  { findRoute(int y, int x + 1)
*/
vector<vector<int>> taken;
int cache[26][26];
int solution(vector<vector<int>> board) {
    int answer = 0;



    return answer;
}

int main() {
	vector<vector<int>> board = {
		{0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1},
		{0,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,0},
		{1,0,0,0,0,0,0,0}
	};
	cout << solution(board) << '\n';
	return 0;
}
