#include <stdio.h>
#define ROWS 4
#define COLS 4

void print_array(int array1[ROWS][COLS], int array2[ROWS][COLS]) {
	int result[ROWS][COLS];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			result[i][j] = array1[i][j]*array2[i][j];
			printf("%d  ", result[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int mun1[ROWS][COLS] = { { 1,2,3,4 },{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int mun2[ROWS][COLS] = { {4,3,2,1 },{8,7,6,5},{12,11,10,9},{16,15,14,13} };
	print_array(mun1, mun2);
	
	return 0;
}