#include <iostream>
#include <string>
using namespace std;

void f(string print="", int line = 1) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++) {
			cout << print;
		}
		cout << endl;
	}
}

int main() {
	f(); //한줄에 빈칸을 10개 출력한다.
	f("%"); //한줄에 ' % '를 10개 출력한다.
	f("@", 5); //5줄에 '@'문자를 10개 출력한다.
}