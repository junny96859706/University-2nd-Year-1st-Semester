#include <stdio.h>

int A(int x);

int main() {
	int a = 10;
	int b = 10;

	b = A(a);
	printf("a = %d : b = %d\n", a, b);
}