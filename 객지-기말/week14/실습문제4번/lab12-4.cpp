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
	ofstream fout("c:\\temp\\system.txt", ios::out);
	if (!fout) {
		cout << "파일이 제대로 열리지 않았습니다" << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get()) != EOF) {
		fout << (char)toupper(ch);
	}

	fin.close();
	fout.close();
}