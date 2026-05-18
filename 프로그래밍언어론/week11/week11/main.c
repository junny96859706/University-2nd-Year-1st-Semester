#include <stdio.h>

int big;
void add(int *a, int *b); //함수선언

int main() {
	int i = 2;

	add(&i, &big);
                	printf("i = %d : big = %d\n", i, big);

	return 0;
}