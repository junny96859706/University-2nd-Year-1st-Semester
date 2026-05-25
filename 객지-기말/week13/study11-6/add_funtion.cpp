#include <iostream>
using namespace std;

int main() {
	int m; //변수m 선언. 정수를 저장하는 변수 m
	void print(int); //함수 print의 원형을 선언
	void (*f)(int); //선언문. 변수f를 선언
	//void를 리턴하고 매개변수가 정수타입인
	//함수의 주소를 저장하는 변수 f 선언

	//print(5);

	//함수의 이름은 함수의 주소!!
	f = print; //포인터 변수f에 print함수의 주소저장
	f(5); //print함수 호출!
}

void print(int n) {
	cout << n;
}
