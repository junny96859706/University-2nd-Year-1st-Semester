#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin;
	fin.open("c:\\temp\\ex12-6.cpp", ios::in);
	if (!fin) {
		cout << "파일이 제대로 열리지 않았습니다//" << endl;
		return 0;
	}

	ofstream fout("c:\\temp\\extest.cpp");
	if (!fout) {
		cout << "파일이 제대로 열리지 않았습니다." << endl;
		return 0;
	}
	
	string line;
	while (getline(fin, line)) {
		//만약 주석(//)이 없는 평범한 줄을 읽었을 때 line.find("//")를 실행하면 
		// 이상한 큰 숫자(string::npos)를 돌려준다.(그래서 if문사용해야한다)
	
		// 1. 주석의 위치(방 번호)를 찾아서 변수에 넣어준다.
		int commentPos = line.find("//");

		if (commentPos != string::npos) {
			//0번 방(처음)부터 주석 직전(commentPos) 개수만큼만 잘라서 원본에 덮어쓰기
			line = line.substr(0, commentPos);
		}

		// 이렇게 하면 주석이 지워진 깨끗한 line만 출력된다!
		fout << line << endl;
	}

	fin.close();
	fout.close();
}