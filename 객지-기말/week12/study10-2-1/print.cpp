#include <iostream>
using namespace std;

//템플릿 함수 보다 중복 함수가 우선!!
template <class X>
void print(X array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << '\t';
	}
	cout << endl;
}

void print(char array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << (int)array[i] << '\t';
	}
	cout << endl;
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5] = { 1.1,2.2,3.3,4.4,5.5 };

	print(x, 3);
	print(d, 4);

	char c[] = { 1,2,3,4,5 }; //문자'1'과 숫자1을 구분해야한다!!! ->1은 진짜 숫자/'1'은 아스키코드 49
	//char g[] = {'1','2','3','4','5' }; 는 { 49, 50, 51, 52, 53 }; 과 같다!!!!
	print(c, 4);
}