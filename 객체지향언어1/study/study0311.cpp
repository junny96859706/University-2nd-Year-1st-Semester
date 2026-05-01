#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cout << "수현이 최애 음식은 무엇일까요?" << "end1";
	cout << "1.마라탕," << endl;
	cout << "2.엽떡," << endl;
	cout << "3.훠궈," << endl;
	cout << "4.지형이" << endl;

	char password[100];
	while (true) {
		cout << "답을 입력하시오:";
		cin.getline(password, 100);
			if (strcmp(password, "지형이") == 0) {
				cout << "헐 당신은 사랑꾼 쿼카군요!!! 멋져요!";
				break;
			}
			else
				cout << "아닌데아닌데? 풉ㅋ";

		}
	}