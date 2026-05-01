#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char buf[100];
	while (1) {
		cout << "끝내려면 OK를 입력하세요>>";
		cin.getline(buf, 100);

		if ((strcmp(buf, "ok") == 0)) {
			cout << "종료합니다.";
			break;
		}
	}
}