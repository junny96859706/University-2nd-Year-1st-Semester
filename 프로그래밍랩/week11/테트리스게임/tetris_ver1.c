//테트리스 게임 만들기  
#define _CRT_SECURE_NO_WARNINGS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h> //getch를 위한 헤더
#include <time.h>

//방향키 아스키 코드
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

//게임판 출력 위치
#define BX 5
#define BY 1

//게임판 크기
#define BW 10
#define BH 20

//커서 표시 여부
#define NOCURSOR 0
#define NOMALCURSOR 1

//게임판 상태값
#define EMPTY 0
#define BRICK 1
#define WALL 2

//BOOL 타입 정의
typedef int BOOL;
#define TRUE 1
#define FALSE 0

//블록 좌표 구조체 정의
typedef struct Point {
	int x, y;
}Point;

//테트리스 블록 데이터 정의(7가지 블록과 4가지 회전 상태)
//Shape[블록 번호][회전 상태][블록 4칸의 좌표]
Point Shape[][4][4] = {
	//0번블록 :l자형
	{
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}},
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}}
},//1번블록: ㅁ자형
{
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}}
},//2번블록: 
{
	{{0,0},{-1,0},{0,-1},{1,-1}},
	{{0,0},{0,1},{-1,0},{-1,-1}},
	{{0,0},{-1,0},{0,-1},{1,-1}},
	{{0,0},{0,1},{-1,0},{-1,-1}} // 0.1 오타 수정
},//3번블록:ㄹ자형
{
	{{0,0},{-1,-1},{0,-1},{1,0}},
	{{0,0},{-1,0},{-1,1},{0,-1}},
	{{0,0},{-1,1},{0,-1},{1,0}},
	{{0,0},{-1,0},{-1,1},{0,-1}}
},//4번블록: ㄴ자형
{
	{{0,0},{-1,0},{1,0},{-1,-1}},
	{{0,0},{0,-1},{0,1},{-1,1}},
	{{0,0},{-1,0},{1,0},{1,1}},
	{{0,0},{0,-1},{0,1},{1,-1}}
},//5번블록:ㄱ자형
{
	{{0,0},{1,0},{-1,0},{1,-1}},
	{{0,0},{0,1},{0,-1},{-1,-1}},
	{{0,0},{1,0},{-1,0},{-1,1}},
	{{0,0},{0,-1},{0,1},{1,1}}
},//6번 블록:T자형
{
	{{0,0},{-1,0},{1,0},{0,1}},
	{{0,0},{0,1},{0,-1},{-1,-1}},
	{{0,0},{1,0},{-1,0},{-1,1}},
	{{0,0},{0,-1},{0,1},{1,1}}
}
};

// 위쪽에 따로 있던 int rot; 중복 선언 제거
char* arTile[] = { "  ","■","□" };
int board[BW + 2][BH + 2]; //게임판 배열
int brick, rot;
int nx, ny; //현재블록의 위치 가져오기

void gotoXY(int x, int y) {
	COORD pos;
	pos.X = (SHORT)(x - 1);
	pos.Y = (SHORT)(y - 1);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}void DrawBoard() {
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			gotoXY(BX + x * 2, BY + y);
			printf("%s", arTile[board[x][y]]);
		}
	}
}void PrintBlock(int block, int startX, int startY) {
	//각블록 4칸 출력
	for (int i = 0; i < 4; i++) {
		int x = startX + Shape[block][rot][i].x * 2; //블록 간격을 2로 설정해서 출력
		int y = startY + Shape[block][rot][i].y;

		gotoXY(x, y);
		printf("■");
	}
}void printBrick(BOOL show) {
	for (int i = 0; i < 4; i++) {
		gotoXY(BX + (Shape[brick][rot][i].x + nx) * 2,
			BY + Shape[brick][rot][i].y + ny);
		//show가 TRUE면 벽돌을 출력, FALSE면 빈칸을 출력하여 벽돌을 지움
		printf("%s", arTile[show ? BRICK : EMPTY]);
	}
}int GetAround(int x, int y, int b, int r) {
	// x: 블록 x좌표, y: 블록y좌표, b: 블록번호, r:회전상태

	int k = EMPTY; //주변 상태값 초기화
	int value;

	for (int i = 0; i < 4; i++) {
		value = board[x + Shape[b][r][i].x][y + Shape[b][r][i].y];
		if (value > k) {
			k = value; //가장 높은 상태값을 반환(WALL > BRICK > EMPTY)
		}
	}
	return k;
}void TestFull() {
	int i, x, y, ty;

	for (i = 0; i < 4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = BRICK;
	}

	//모든 줄 검사
	for (y = 1; y < BH + 1; y++) {
		for (x = 1; x < BW + 1; x++) {
			//빈칸이 존재하면 종료
			if (board[x][y] != BRICK)
				break;
		}

		//끝까지 순회했으면 한 줄 완성
		if (x == BW + 1) {
			//위 줄들을 아래 줄로 복사
			for (ty = y; ty > 1; ty--) {
				for (x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}

			DrawBoard();
			Sleep(200); //200ms
		}
	}
}BOOL MoveDown() {
	//아래에 충돌이 존재하면
	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		return TRUE;
	}

	printBrick(FALSE);
	ny++;
	printBrick(TRUE);
	return FALSE;
}BOOL ProcessKey() {
	int ch, trot;

	if (_kbhit()) {
		ch = _getch();
		if (ch == 224) {
			ch = _getch();

			switch (ch) {
			case LEFT:
				if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
					printBrick(FALSE);
					nx--;
					printBrick(TRUE);
				}
				break;
			case RIGHT:
				if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
					printBrick(FALSE);
					nx++;
					printBrick(TRUE);
				}
				break;
			case UP:
				trot = (rot == 3 ? 0 : rot + 1);
				if (GetAround(nx, ny, brick, trot) == EMPTY) {
					printBrick(FALSE);
					rot = trot; // rot = TRUE; 에서 변경
					printBrick(TRUE);
				}
				break; // break; 추가
			case DOWN:
				if (MoveDown())
					return TRUE;
				break;
			}
		}
		else {
			if (ch == ' ') {
				while (MoveDown() == FALSE);
				return TRUE;
			}
		}
	}
	return FALSE;
}int main(void) {
	int ch;
	int nFrame; //블록이 내려오는 속도
	int nStay; //현재 남아있는 시간 카운트

	srand((unsigned int)time(NULL));

	system("cls");

	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			if (x == 0 || x == BW + 1 || y == BH + 1) {
				board[x][y] = WALL;
			}
			else
				board[x][y] = EMPTY;
		}
	}

	DrawBoard();
	nFrame = 20;

	//게임 전체 반복 루프
	while (1) {
		brick = rand() % (sizeof(Shape) / sizeof(Shape[0]));
		//Shape 배열 크기만큼 랜덤한 블록 선택

		nx = BW / 2; //블록 시작 x위치
		ny = 3; //블록 시작 y위치
		rot = 0;

		printBrick(TRUE);

		// 바닥 충돌 시 즉시 게임오버되는 버그 수정 (생성 위치가 막혔을 때만 탈출)
		if (board[nx][ny] != EMPTY || GetAround(nx, ny, brick, rot) == WALL)
			break;

		nStay = nFrame;

		//현재 블록 처리 반복 루프
		while (1) {
			if (--nStay == 0) {
				nStay = nFrame;

				if (MoveDown())
					break;
			}

			if (ProcessKey())
				break;
			Sleep(50);
		}
	}

	//게임 종료후
	system("cls");
	gotoXY(30, 12);
	printf("GAME OVER\n");

	return 0;
}