#include <stdio.h>
#define SIZE 5

void print_image(int image[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < SIZE; k++)
			printf("%03d ", image[i][k]);
		printf("\n");
	}
	printf("\n");
}

void brighten_image(int  image[SIZE][SIZE]) { //포인터사용하여 각원소에 10더하기!!!!
	int* p; //주소저장 포인터 변수
	p = &image[0][0]; //2차원배열의 첫번째 요소 주소 저장

	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < SIZE; k++) {
			*p += 10;
			p++; //다음요소로 이동 
		}
	}
}

int main(void) {
	int image[SIZE][SIZE] = {
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50}
	};
	print_image(image);
	brighten_image(image);
	print_image(image);
}