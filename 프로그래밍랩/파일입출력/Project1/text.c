#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//a의 문자열을 복사해서 b텍스트 파일에 저장하기
int main() {

	FILE* fp1, * fp2;
	char file1[100];
	char file2[100];

	printf("원본 파일 이름:");
	scanf("%s", file1);
	printf("복사 파일 이름:");
	scanf("%s", file2);

	fp1 = fopen(file1, "r");
	if (fp1 == NULL) {
		fprintf(stderr, "원본파일 %s를 열수 없습니다.\n", file1);
		exit(1);
	}

	fp2 = fopen(file2, "w");
	if (fp2 == NULL) {
		fprintf(stderr, "원본파일 %s를 열수 없습니다.\n", file2);
		exit(1);
	}

	int c;
	while ((c = getc(fp1)) != EOF)
		fputc(c,fp2);
	fclose(fp1);
	fclose(fp2);
	


}