#include <iostream>
using namespace std;
//6-1장:함수 중복
//함수 중복의 편리함: 동일한 이름을 사용하면 함수이름을 구분하여 기억할 필요없고, 
// 함수호출을 잘못하는 실수를 줄일수 있음

int big(int a, int b) {
	if (a > b) return a;
	else return b;
}

int big(int a[], int size) {
	int biggest = a[0];

	for (int i = 0; i < size; i++) {
		if (biggest < a[i])
			biggest = a[i];
	}

	return biggest;
}

int main() {
	cout << big(2, 3) << endl;
	
	int array[5] = { 1,9,-2,8,6 };
	cout << big(array, 5) << endl;

	cout << sum
}