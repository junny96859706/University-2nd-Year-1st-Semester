#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char user[100]; //사용자로부터 입력받은 문자열 암호를 저장하는 배열
	//루프를 돌면서 문자열을 입력받고, 암호와 비교하여 같으면 종료,아니면 계속 루프
	//string user;를 쓰면 if(user == "c++"){를 사용할수있다.

	while (true) {
		cout << "암호입력:";
		cin.getline(user,100,'\n') >> user;

		cout << strlen(user) << "개" << endl;

		if (strcmp(user,"c++ good")==0) {
			cout << "통과";
			break;
		}
		else
			cout << "틀렸어요 다시 입력:" << endl;
	}
}
