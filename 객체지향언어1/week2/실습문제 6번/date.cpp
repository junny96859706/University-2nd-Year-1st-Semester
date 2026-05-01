#include <iostream>
#include <string>
using namespace std;

int main() {
	string day;
	while (1) {
		int num = 1;
		int start = 0;
		cout << "3월 1일은 무슨 요일입니까??>>";
		cin >> day;

		/*
		if (day == "월") {
			start = 1;
			num = 7;
		}
		else if (day == "화") {
			start = 2;
			num = 6;
		}
		else if (day == "수") {
			start = 3;
			num = 5;
		}
		else if (day == "목") {
			start = 4;
			num = 4;
		}
		else if (day == "금") {
			start = 5;
			num = 3;
		}
		else if (day == "토") {
			start = 6;
			num = 2;
		}
		else if (day == "일") {
			start = 0;
			num = 8;
		}
		*/

		string days[] = { "일", "월", "화", "수", "목", "금", "토" };
		for (int i = 0; i < 7; i++) {
			if (day == days[i]) {
				start = i; // 인덱스 번호를 찾음 (0~6)
				num = 8 - start;
				break;
			}
		}

		cout << "일\t" << "월\t" << "화\t" << "수\t" << "목\t" << "금\t" << "토\t" << endl;

		for (int i = 0; i < start; i++) {
			cout << " " << "\t";
		}

		for (int i = 1; i < num; i++) {
			cout << i << "\t";
		}
		cout << endl;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {
				if (num < 32) {
					cout << num << "\t";
					num++;
				}
			}
			cout << endl;
		}
	}
}