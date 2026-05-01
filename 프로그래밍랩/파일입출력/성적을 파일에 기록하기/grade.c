#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//학생들의 성적을 형식화된 입출력을 사용하여 텍스트파일에 저장하는 프로그램을 작성하기
int main() {

	FILE* fp;
	int number;
	char name[30], ch;
	int score;

	fp = fopen("score.txt", "w");
	if (fp == NULL) {
		fprintf(stderr, "원본파일 score.txt를 열수 없습니다.\n");
		exit(1);
	}

	do {
		printf("학번:");
		scanf("%d", &number);
		printf("이름:");
		scanf("%s", &name);
		printf("성적:");
		scanf("%d", &score);

		fprintf(fp, "%d %s %d\n", number, name, score);
		printf("데이터 추가를 계속??(y/n): ");
		scanf(" %c", &ch);
	} while (ch != 'n');

	fclose(fp);
	return 0;
}