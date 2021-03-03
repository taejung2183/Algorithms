#include <iostream>
#include <vector>
using namespace std;

const double INF = 987654321.0;
int n; // Number of the cities.
vector<vector<double>> distances; // Distances between cities.

// Find the shortest circuit. (You need to get back to where you started.)
// Therefore, where to start is irrelevant. (We start from the [0] city here.)
// Input: 1) Array to record if the specific city was taken. 2) Variable to track the length of the path.
// 		  3) Variable to record current city.
double tsp_circuit(bool taken[10], int current, double length) {
	// Base case: If all the cities were taken, return the length of the path.
	bool isFinished = true;
	for (int i = 0; i < n; ++i) {
		if (taken[i] == false) {
			isFinished = false;
			break;
		}
	}
	// Add the distance to the departure from the last city.
	if (isFinished == true)
		return length + distances[current][0];

	double ret = INF;

	// Task piece: Pick one city and travel.
	for (int next = 1; next < n; ++next) {
		if (taken[next] == true) continue;

		taken[next] = true;
		ret = min(ret, tsp_circuit(taken, next, length += distances[current][next]));
		taken[next] = false;
	}

	return ret;
}

// Find the shortest path. (You don't need to get back to where you started.)
double tsp_path(bool taken[10], int current, double length) {
	// Base case: If all the cities were taken, return the length of the path.
	bool isFinished = true;
	for (int i = 0; i < n; ++i) {
		if (taken[i] == false) {
			isFinished = false;
			break;
		}
	}
	if (isFinished == true)
		return length;

	double ret = INF;

	// Task piece: Pick one city and travel.
	// Unlike tsp_circuit, where to start is not designated.
	// You need to give every city for the iteration.
	for (int next = 0; next < n; ++next) {
		if (taken[next] == true) continue;

		taken[next] = true;
		if (current == -1) 
			ret = min(ret, tsp_path(taken, next, 0));
		else
			ret = min(ret, tsp_path(taken, next, length += distances[current][next]));
		taken[next] = false;
	}

	return ret;
}

int main() {
	int C; cin >> C;
	bool taken[10]; 
	vector<double> answers;
	int current;
	double pathLength;

	while (C-- > 0) {
		cin >> n; // How many cities? (2 <= n <= 10)

		vector<double> row;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				double dist; cin >> dist;
				row.push_back(dist);
			}
			distances.push_back(row);
			row.clear();
		}

		for (auto& e: taken) e = false;
		// Start from the first city.
		pathLength = 0;

		/////////////////// tsp_path ////////////////////
		current = -1;
		answers.push_back(tsp_path(taken, current, pathLength));

		/////////////////// tsp_circuit ////////////////////
		//current = 0;
		//taken[0] = true; 
		//answers.push_back(tsp_circuit(taken, current, pathLength));

		distances.clear();
	}

	for (auto& e: answers) printf("%.10f ", e);
	cout << endl;

	return 0;
}
