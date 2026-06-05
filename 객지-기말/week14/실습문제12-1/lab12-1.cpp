#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int num;
	string word;
	ofstream fout;
	fout.open("c:\\temp\\test.txt",ios::out);
	if (!fout) {
		cout << "파일이 제대로 열리지 않았습니다." << endl;
		return 0;
	}
	cin >> num;
	cin >> word;

	fout << num << endl;
	fout << word << endl;
	fout.close();//출력통로를 확실하게 닫은후, 입력통로를 새로 열기!!!

	ifstream fin("c:\\temp\\test.txt",ios::in); //내가 계속 istream이라 쓴다;;(주의)
	if (!fin) {
		cout << "파일이 제대로 열리지 않았습니다" << endl;
		return 0;
	}

	fin >> num;   //whlie문이 필요없는경우:데이터개수가 확실할때
	fin >> word;  //while문이 필수인 경우: 데이터 개수를 모를때!!!

	cout << "파일에 입력된 숫자>>" << num << endl;
	cout << "파일에 입력된 문자>>" << word << endl;
	fin.close();


}