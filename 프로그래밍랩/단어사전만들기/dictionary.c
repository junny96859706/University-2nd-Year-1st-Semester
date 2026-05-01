#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define WORDS 5

int main() {
	int i, index;
	char dic[WORDS][2][30] = {
		{"book","책"},
		{"boy","소년"},
		{"computer","컴퓨터"},
		{"language","언어"},
		{"rain","비"},
	};
	char word[30];

	while (1) {

		printf("단어를 입력하시오(종료:exit):");
		scanf("%s", word);

		if (strcmp(word, "exit") == 0)
			break;
		int found = 0;

		for (int i = 0; i < WORDS; i++) {
			//영어->한글
			if (strcmp(dic[i][0], word) == 0) {
				printf("%s : %s\n", dic[i][0], dic[i][1]);
				found = 1; //단어를 찾았음
				break;
			}
			//한글->영어
			else if(strcmp(dic[i][1], word) == 0) {
					printf("%s : %s\n", dic[i][1], dic[i][0]);
					found = 1; //단어를 찾았음
					break;
			}
		}

		if (!found) {
			printf("단어를 찾을수 없습니다.\n");
		}
	}
}