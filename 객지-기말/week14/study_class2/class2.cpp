#include <iostream>
#include <fstream>
#include <string> //string의 getline()함수를 쓰기 위해서 헤더 추가
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\windows\\system.ini");
	if (!fin) {
		cout << "열기 실패" << endl;
		exit(0);
	}

	/*int c;
	int count = 0;
	//fin.get()은 단순히 글자만 읽어오는 게 아니라, "현재 커서 위치의 글자를 읽어온 뒤, 
	//커서를 다음 칸으로 밀어내는 일"까지 세트로 처리하는 함수.
	while ((c = fin.get()) != EOF) {
		cout.put(c);
		count++;
	}*/

	string buf;
	while (getline(fin,buf)) {
		cout << buf << endl;
	}

	fin.close();
}