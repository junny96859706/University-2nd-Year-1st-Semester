#include <stdio.h>

int A(int x) {
	printf("x = %d\n", x);
	x = 20;
	return x;
}