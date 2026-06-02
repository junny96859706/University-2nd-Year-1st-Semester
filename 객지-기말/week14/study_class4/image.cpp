//binary모드로 이미지 파일 복사해보기
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\temp\\img.jpg",ios::binary);
	if (!fin) {
		cout << "소스 파일 열기 실패" << endl;
		exit(0);
	}

	ofstream fout("c:\\temp\\dest.jpg",ios::binary);
	if (!fout) {
		cout << "목적 파일 열기 실패" << endl;
		exit(0);
	}

	//ff는 -1이다,바이너리 파일이 아니면 ff를 -1이라고 아스크 코드상 해석!!!->종료!

	char buf[1024];
	while (!fin.eof()) { 
		fin.read(buf, 1024);
		int n = fin.gcount();
		fout.write(buf, n);
		if (n < 1024)
			break;
	}
	
	fin.close();  fout.close();
}