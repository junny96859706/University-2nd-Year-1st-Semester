#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* srcFile = "c:\\temp\\img.jpg";
	const char* destFile = "c:\\temp\\back.jpg";

	ifstream fsrc(srcFile,ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " 열기 실패" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::binary);
	if (!fdest) {
		cout << destFile << " 열기 실패" << endl;
		return 0;
	}
	
	/*
	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	*/

	char buf[1024]; //1024바이트라고 생각
	while (!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n); //마지막에 읽는 바이트수는 1024가 아님을 해결하기 위해서 
	}

	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}