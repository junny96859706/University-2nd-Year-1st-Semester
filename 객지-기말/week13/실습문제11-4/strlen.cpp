#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int num = 0;
	int max = 0;       // 💡 가장 긴 문장의 '방 번호(라인)'를 기억할 변수
	int max_len = 0;   // 💡 역대 가장 긴 '글자 수'를 기억할 기준점 변수

	int len;           // 💡 [배열[80] 대신 일반 변수로 변경!] 방금 읽은 줄의 길이를 임시로 담는 변수
	char buf[80];
	char answer[80] = "";

	cout << "최대79글자 까지 입력 가능합니다." << endl;
	while (true) {
		cout << num + 1 << ":     ";
		cin.getline(buf, 80);

		if (cin.eof())
			break;

		// 1. 방금 입력받은 줄의 길이를 '일반 변수 len'에 저장합니다.
		len = cin.gcount();

		// 2. 첫 번째 입력(num == 0)이거나, 방금 읽은 길이(len)가 역대 1등 길이(max_len)보다 클 때
		if (num == 0 || len > max_len) {
			max_len = len;      // 역대 최고 점수(길이) 갱신
			max = num;          // 역대 최고 라인 번호 갱신
			strcpy(answer, buf); // 1등 문자열을 answer에 안전하게 박제
		}

		num++;
	}

	cout << "가장 긴 문장은 라인 " << max + 1 << ":" << answer << endl;
}