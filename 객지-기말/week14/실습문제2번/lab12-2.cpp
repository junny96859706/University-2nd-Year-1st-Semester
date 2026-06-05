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
	
	int i = 1;
	while (getline(fin, line)) {
		cout << i << " : " << line << endl;
		//endl을 내가 직접출력하는 이유?:getline은 엔터를 만날때까지 입력받고
		//엔터를 제외하고 line변수에 넣는다!!!
		i++;
	}

	fin.close();
}