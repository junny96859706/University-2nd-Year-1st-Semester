#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	char** p;
	p = (char**)malloc(sizeof(char*) * 2);
	for (int i = 0; i < 2; i++) {
		*(p+i) = (char*)malloc(sizeof(char) * 3);
	}
	if (p == NULL) {
		printf("메모리부족으로 동적할당이 실행되지 않았습니다");
		exit(1);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(p + i) + j) = i + 3 + j;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("* (*(p + %d) + %d)의 주소(%p)와 값(%d)\n",i,j,(*(p+i)+j),(*(p+i)+j));
		}
	}
	for (int i = 0; i < 2; i++) {
		free(*(p + i));
	}
	free(p);
	return 0;
}