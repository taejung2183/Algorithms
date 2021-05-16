#include <iostream>
using namespace std;

/*
   1 2 3 4 5 6 7 8 9 10
   => 숫자 3개로 양자화

   1~10 중에 3개를 고르는 방법 (조합)
   각 숫자마다 고른 3개 숫자 중 차이가 적은 것으로 치환한다.

    // 최대 길이 100
   	array<int, 10> origin = {1,2,3,4,5,6,7,8,9,10};
	// 10C3 으로 quantizedNum 을 초기화 (반복문으로 모든 경우 순회)
   	array<int, 3> quantizedNum;
	// 최대 길이 100인 수열에서 3가지 양자화 숫자를 고르는 시간 복잡도.
	// 100C3 => 970k

	for (int i = 1; i <= 10; ++i) {
		int min = quantizedNum[0];
		int minDiff = quantizedNum[0] - origin[i];
		
		// Find the closest quantized number with i.
		for (int j = 1; j < qunatizedNum.size(); ++j) {
			if (abs(quantizedNum[j] - origin[i]) < minDiff) {
				min = quantizedNum[j]; 
			}
		}
		// Change the original element with quantized number.
		origin[i] = min;
	}
 */

int main() {
	return 0;
}
