#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10];
	int sid;
	char dept[20];

	cout << "이름>>";
	cin >> name;
	cout << "학번(숫자로)";
	cin >> sid;
	cout << "학과>>";
	cin >> dept;

	ofstream fout("c:\\temp\\student.txt");
	if (!fout) { // fout.operater!() 연산자 함수를 호출하는 것
		return 0; //열기실패. 더 이상 쓰기 안됨
	}

	fout << name << endl;
	fout << sid << endl; //텍스트 파일에 쓰기중. 숫자가 문자로 바뀌어 저장
	fout << dept << endl;

	fout.close();

}