#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h> //난수생성함수등을 포함

int main(woid)
{
	
	int i, number,result;
	printf("알고싶은 구구단을 입력하시오:");
	scanf_s("%d", &number);
	
	for (i = 1; i < 10; i++) {
		result = i * number;
		printf("%d * %d = %d\n", number, i, result);
	}

	return 0;

}

/*
printf("연도를 입력하시오:");
scanf("%d", &year);
printf("%d년은 윤년입니다.\n", year);
*/