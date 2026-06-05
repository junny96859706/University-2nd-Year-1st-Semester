#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

	string line;
	ifstream fin("c:\\windows\\system.ini", ios::in);
	if (!fin) {
		cout << "파일을 읽을수 없습니다." << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get())!= EOF) {
		cout << (char)toupper(ch);
	}
	

	fin.close();

}