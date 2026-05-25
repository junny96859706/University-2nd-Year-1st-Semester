#include <iostream>
using namespace std;

void get1() {
	cout << "cin.get()으로 문자 입력 사례>>";
	int ch; //읽은 문자를 저장할변수, int 타입으로 반드시 선언
	while((ch = cin.get()) != EOF) { //스트림 끝
		cout.put(ch);
		if (ch == '\n')
			break;
	}
}

void get2() {
	cout << "cin.get()으로 문자 입력 사례>>";
	char ch;
	while (true) {
		cin.get(ch); //ch에다가 읽어달라는 뜻.
		if (cin.eof()) break;
		cout.put(ch); //읽은 문자를 화면에 출력
		if (ch == '\n')
			break;
	}
}

int main() {
	get1();
	get2();
}