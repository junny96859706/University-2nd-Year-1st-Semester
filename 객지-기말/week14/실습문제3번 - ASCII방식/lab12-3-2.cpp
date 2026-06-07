#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream fin("c:\\windows\\system.ini", ios::in);
	if (!fin) {
		cout << "파일이 제대로 열리지 않았습니다" << endl;
		return 0;
	}
	int ch;
	
	while ((ch = fin.get()) != EOF) {

		if (ch >= 'a' && ch <= 'z') {
			cout << (char)(ch - 32); // 소문자일 때만 대문자로 변환
		}
		else {
			cout << (char)ch;        // 이미 대문자이거나 숫자, 공백, 엔터면 그대로 출력!
		}
	}

	fin.close(); //계속까먹는데 까먹으면 감점당한다
}