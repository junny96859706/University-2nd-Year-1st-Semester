#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct test {
	int i;
	char str[20];
};

int main() {
	struct test* p;
	p = (struct test*)malloc(sizeof(struct test));
	if (p == NULL) {
		printf("메모리가 부족해서 할당할수 없습니다");
		exit(1);
	}
	p->i = 100;
	strcpy(p->str, "just testing");
	printf("i: %d\n", p->i);  //p->i; == (*p).i;
	printf("str: %s\n", p->str);
	free (p);
	return 0;
	
}