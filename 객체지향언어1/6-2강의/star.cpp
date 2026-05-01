#include <iostream>
using namespace std;

void f(char a = ' ', int line = 1); //원형선언

//함수구현
void f(char a, int line) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++)
			cout << a;
		cout << endl;
	}
}

int main() {

	f(); //한줄에 빈칸을 10개 출력한다.
	f('%'); //한줄에 '%'fmf 10개 출력한다.
	f('@',5); //5줄에 '@'문자를 10개 출력한다.
}