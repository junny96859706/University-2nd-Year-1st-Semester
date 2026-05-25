#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cout << "cin.getline()으로 한줄 읽기" << endl;
	cout << "exit을 입력하면 루프가 끝납니다" << endl;

	char line[80];
	int no = 1;
	while (true) {
		cout << "라인 " << no << ">> ";
		cin.getline(line, 80, '\n'); 
		//'\n'은 디폴트 매개변수 => \n을 버퍼에서 제거
		if (strcmp(line, "exit") == 0)
			break;
		cout << line << endl;
		no++;
	}
}