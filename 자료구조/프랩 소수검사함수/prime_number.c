#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_prime(int n) { //소수구하기 함수
	int is_prime = 1;
	int i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			is_prime = 0;
			break;
		}
	}
	return is_prime;
}

int main() {
	int k, flag = 0;
	printf("양의정수를 입력하시오: ");
	scanf("%d", &k);

	for (int i = 2; i < k; i++) {
		if (check_prime(i) == 1) {
			if (check_prime(k - i) == 1) {
				printf("%d = %d + %d\n", k, i, k - i);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf(" % d는 소수들의 합으로 표시될수 없습니다.\n", k);
	
	return 0;
}