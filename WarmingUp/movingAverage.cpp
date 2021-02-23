#include<iostream>
#include<vector>
using namespace std;

vector<float> movingAverage(vector<float> weight,int num){
	/*
	   Inefficient moving average, O(n^2)
		Idea:Simple iteration for getting partial summation and average.
	float partialSum;
	vector<float> movingAverage;

	for(int front = 0; front <= weight.size() - num; ++front){
		partialSum = 0;

		for(int i = front; i < front + num; ++i) partialSum += weight[i];

		float average = partialSum / num;
		movingAverage.push_back(average);
	}
	*/
	
	float partialSum = 0;
	vector<float> movingAverage;
	/*
	   Better moving average, O(n)
		Idea:You don't need to repeat the calculation of past two months when you 
	   			move one month forward, just drop the record at the front.
	   */
	//1.Calculate summation of two months 2.Add one month and get average
	//3.Drop the first month's record 4. repeat 2,3
	for(int front = 0; front < num - 1; ++front) partialSum += weight[front];
	for(int front = num - 1; front < weight.size(); ++front){
		partialSum += weight[front];
		movingAverage.push_back(partialSum / num);
		partialSum -= weight[front - num + 1];
	}

	return movingAverage;
}

int main(){
	vector<float> weight = {73.1, 73.6, 74.0, 73.3, 72.2, 71.9, 72.8};
	vector<float> answers;
	int stride = 3;

	answers =  movingAverage(weight, stride);
	for(auto e: answers) cout << e << " ";
	cout << endl << "DONE\n";

	return 0;
}
