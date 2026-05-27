#include <iostream>
#include <iomanip>
#include <cctype> //isprint함수 사용을 위한 헤더 선언
using namespace std;

//0에서 127까지 아스키코드와 해당 문자를 다음과 같이 출력하는 프로그램을 작성하라.
//문자로 출력 가능하지 않는 아스키 코드는 '.'으로 출력하라. (문제11-6번)

int main() {

	for (int i = 0; i < 4; i++) {
		cout << left << setw(10) << "dec";
		cout << setw(10) << "hexa";
		cout << setw(10) << "char";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << "___";
		cout << setw(10) << "____";
		cout << setw(10) << "____";
	}

	//본문 출력
	for (int i = 0; i <= 60; i += 4) {
		for (int j = 0; j < 4; j++) {
			cout << dec << setw(10) << i+j;
			cout << hex << setw(10) << i+j;
			if (isprint(i + j)) {
				cout << setw(10) << (char)(i + j); //(char)i+j라고 하면 안된다!!! i만 형변환 한다.
			}
			else
				cout << setw(10) << ".";
		}
		cout << endl;
	}

	cout << dec << right << setfill('-') << setw(60) << "이하생략";
	cout << left << setfill('-') << setw(60); //setfill()도 계속 유지되서 굳이 안넣어도 된다!!!!

}