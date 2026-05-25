#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char cmd[80]; //79개의 문자까지 저장가능한 배열
	cout << "cin.get()을 이용하여 문자열 읽기" << endl;
	while (true) {
		cout << "종료하려면 exit를 입력하세요>>";
		cin.get(cmd, 80); //'\n'이 입력되거나 79개 문자를 입력할때 리턴
		if (strcmp(cmd, "exit") == 0) {
			cout << "프로그램을 종료합니다." << endl;
			break; //return 0으로 해도 됨!
		}
		else {
			cin.ignore(1); //키보드버퍼에 남아있는 한글자를 무시하라
		}
	} 
}