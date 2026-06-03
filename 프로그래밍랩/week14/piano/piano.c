#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//도레미파솔라시도
#define DO 523
#define RE 587
#define ME 659
#define FA 698
#define SOL 784
#define LA 880
#define SI 988
#define DO_HIGH 1046	

int main(void) {
	int key;

	printf("==============================\n");	
	printf("      피아노 프로그램         \n");
	printf("==============================\n");
	printf("A: 도\n");
	printf("S: 레\n");
	printf("D: 미\n");
	printf("F: 파\n");
	printf("G: 솔\n");
	printf("H: 라\n");
	printf("J: 시\n");
	printf("K: 높은 도\n");
	printf("ESC: 종료\n");
	printf("==============================\n");

	while (1) {
		key = _getch();

		switch (key) {
		case 'a':
		case 'A':
			Beep(DO, 500);
			break;

		case 's':
		case 'S':
			Beep(RE, 500);
			break;

		case 'd':
		case 'D':
			Beep(ME, 500);
			break;

		case 'f':
		case 'F':
			Beep(FA, 500);
			break;

		case 'g':
		case 'G':
			Beep(SOL, 500);
			break;

		case 'h':
		case 'H':
			Beep(LA, 500);
			break;

		case 'j':
		case 'J':
			Beep(SI, 500);
			break;

		case 'k':
		case 'K':
			Beep(DO_HIGH, 500);
			break;

		case 27:
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
	}

	return 0;

}
