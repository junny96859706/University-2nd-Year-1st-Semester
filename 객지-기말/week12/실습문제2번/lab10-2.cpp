#include <iostream>
using namespace std;

template <class T>
void print(T a,T b) {
	for (T i = a; i <= b; i++) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	print(500, 507); //500에서 507까지 1 간격으로 출력
	print(3.5, 6.5); //3.5에서 6.5까지 1.0 간격으로 출력
	print('b', 'y'); //문자 'b'에서 'y'까지 한 문자 간격으로 출력
}