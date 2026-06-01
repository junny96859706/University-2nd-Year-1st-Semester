#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";
	//ifstream fin; // >> 연산자, get()멤버함수 등등 있다
	//fin.open(file); //fin.open(file,ios::in);
	
	ifstream fin(file); //text 모드
	//ifstream fin(file,ios::binary); //바이너리 모드
	
	if(!fin) { //실패한 경우
		cout << "파일" << file << "열기 실패" << endl;
		return 0;
	}

	int line = 0; //라인수를 나타내는 정수
	int count = 0; //문자수를 나타내는 정수
	int c;
	while ((c=fin.get()) != EOF) { //EOF파일의 끝을 만날때까지
		cout << (char)c; //get()은 파일에서 한 바이트씩 순서대로 
		if (c == '\n')
			line++;
		count++;
	}

	cout << "읽은 바이트수(문자수): " << count << endl;
	cout << "읽은 라인수: " << line << endl;
	fin.close();
}

