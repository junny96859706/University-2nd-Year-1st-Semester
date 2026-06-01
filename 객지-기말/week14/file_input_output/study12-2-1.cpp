#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\song.txt");

	if(!fin){//참이라면, 열기 실패
		return 0;
	}

	string line;
	fin >> line;
	cout << line << endl;
	fin >> line;
	cout << line << endl;
	fin >> line;
	cout << line << endl;

	fin.close(); //파일 닫기. fin과 파일의 연결 해제
}