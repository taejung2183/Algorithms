#include <iostream>
using namespace std;

int fastSum(int n){
	// Base case: The sum of natural number ends at 1.
	if(n == 1) return 1;
	// Take care of the odd number input.
	if(n % 2 == 1) return fastSum(n - 1) + n;
	// The formula below only works for even number n.
	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

int main(){
	int n; cin >> n;
	cout << fastSum(n) << endl;

	return 0;
}
