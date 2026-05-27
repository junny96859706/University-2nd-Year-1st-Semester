#include <stdio.h>
#include <Windows.h>

#define WIDTH 10
#define HEIGHT 5

void DrawCharacter(int posY, HANDLE hConsole) {
	char pixel = 219;

	char screen[HEIGHT][WIDTH] = {
		{0,0,pixel,pixel,pixel,pixel,0,0,0,0},
		{0,pixel,0,0,0,0,pixel,0,0,0},
		{pixel,0,pixel,0,0,pixel,0,pixel,0,0},
		{pixel,0,0,0,0,0,0,pixel,0,0},
		{0,pixel,pixel,pixel,pixel,pixel,pixel,0,0,0}
	};

	for (int i = 0; i < posY; i++) {
		printf("\n");
	}

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (screen[y][x] == 0) {
				printf(" ");
			}
			else {
				SetConsoleTextAttribute(hConsole, 10);
				printf("%c", screen[y][x]);
			}
		}
		printf("\n");
	}
}

int main() {
	//콘솔화면을 제어할수 있는 핸들을 가져와라
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleOutputCP(437); //아스키코트를 출력할수 있게끔 설정

	//커서 숨기기
	CONSOLE_CURSOR_INFO cursorinfo = { 1,FALSE };
	SetConsoleCursorInfo(hConsole, &cursorinfo);
	
	int posY = 0;
	int direction = 1;

	while (1) {
		system("cls"); //화면지우기
		DrawCharacter(posY, hConsole);

		posY += direction;

		if (posY >= 3)
			direction = -1;
		if (posY <= 0)
			direction = 1;

		Sleep(100);
		
	}

	/*for (int i = 1; i <= 15; i++) {
		SetConsoleTextAttribute(hConsole, i);

		for (int j = 0; j < 5; j++) {
			printf("%c", pixel);
		}
		printf("Color %d\n", i);
	}
	*/
	SetConsoleTextAttribute(hConsole, 7);
		
	return 0;
}