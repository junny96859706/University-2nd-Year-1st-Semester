#include <stdio.h> //배열의 평균구하기 알고리즘
#define SIZE 5

//배열평균계산 함수
double get_array_avg(int values[], int n) {
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += values[i];
	return sum / n;
}

//배열출력함수
void print_array(int values[], int n) {
	printf("[ ");
	for (int i = 0; i < n; i++)
		printf("%d ", values[i]);
	printf("]\n");
}

int main(){
	int data[SIZE] = { 10,20,30,40,50 };
	print_array(data, 5);
	double result = get_array_avg(data, 5);
	printf("배열의 평균은 %lf", result);
	return 0;
}
