#include <stdio.h>
#include <stdlib.h> //rand,srand
#include <time.h>
#define _CRT_SECURE_NO_WARINGS

enum game {
	scissor,
	rock,
	paper
};

int main() {
	enum game user;
	enum game computer;

	while (1) {
		printf("가위(0),바위(1),보(2) / 종료(-1):");
		scanf("%d",&user);

		//종료조건
		if (user == -1) {
			printf("게임 종료\n");
			break;
		}

		srand((unsigned int)time(NULL)); //랜덤 시드값 설정
		computer = rand() % 3;
		printf("사용자:%d, 컴퓨터:%d\n", user, computer);

		if (user == computer)
			printf("비겼습니다\n");

		else if ((user == scissor && computer == paper) ||
			(user == scissor && computer == paper) ||
			(user == scissor && computer == paper)) {
			printf("사용자가 이겼습니다\n");
		}
		else {
			printf("컴퓨터가 이겼습니다\n");
		}
		printf("\n");
	}
	return 0;
}