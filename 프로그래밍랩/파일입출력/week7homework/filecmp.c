#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	FILE* fp1, * fp2;
	char file1_name[100];
	char file2_name[100];
	char word1[100], word2[100];
	int equal = 0;

	printf("2371214이지형:프랩7주차과제\n");
	printf("첫번째 파일 이름:");
	scanf("%s", file1_name);
	printf("두번째 파일 이름:");
	scanf("%s", file2_name);

	fp1 = fopen(file1_name, "r");
	if (fp1 == NULL) {
		fprintf(stderr, "원본파일 %s를 열수 없습니다.\n", file1_name);
		exit(1);
	}

	fp2 = fopen(file2_name, "r");
	if (fp2 == NULL) {
		fprintf(stderr, "원본파일 %s를 열수 없습니다.\n", file2_name);
		exit(1);
	}

	while (1) {
		char* p1 = fgets(word1, 124, fp1);
		char* p2 = fgets(word2, 124, fp2);
		if (p1 == NULL && p2 == NULL)
			break;

		if (strcmp(word1, word2) == 0) {
			equal = 1;
			break;
		}
		else
			equal = 0;

	}

	if (equal)
		printf("\n파일은 서로 일치함");
	else {
		printf("파일은 일치하지 않음.\n");
		printf("<< %s >> %s", word1, word2);
	}

	fclose(fp1);
	fclose(fp2);


	
}