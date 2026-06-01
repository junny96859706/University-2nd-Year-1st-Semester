#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	int count = 0;
	char buf[81];
	while (fin.getline(buf, 81)) { //80개의 문자를 읽어줘. 라인으로
		cout << buf << endl;
		count++;
	}

	cout << "라인 수는 " << count << endl;
	fin.close();
}