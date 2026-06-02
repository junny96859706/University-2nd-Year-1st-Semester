#include <iostream>
#include <fstream>
using namespace std;

void write() {
	char name[100], dept[100];
	int id;

	cout << "이름을 입력하세요>>";
	cin >> name;
	cout << "학번을 입력하세요>>";
	cin >> id;
	cout << "학과를 입력하세요>>";
	cin >> dept;

	ofstream fout;
	fout.open("c:\\temp\\student.txt",ios::out | ios::app); //fstream 객체 생성....student.txt파일 열기
	if (!fout) { // fout.operator!()연산자 재정의
		cout << "열기 실패" << endl;
		exit(0);
	}

	fout << name << endl;
	fout << id << endl;
	fout << dept << endl;

	fout.close();
}

void read() {

	char name[100], dept[100];
	int id;

	ifstream fin;
	fin.open("c:\\temp\\student.txt",ios::in );

	if (!fin) {
		cout << "열기 실패" << endl;
		exit(0);
	}

	fin >> name >> id >> dept;
	cout << name << ' ' << id << ' ' << dept << endl;
	fin.close();

}


int main() {
	write();
	
}