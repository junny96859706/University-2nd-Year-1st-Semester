//테트리스 게임 만들기  
#define _CRT_SECURE_NO_WARINGS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
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
},
//1번블록: ㅁ자형
{
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1},{1,1}}
},
//2번블록: 
{
	{{0,0},{-1,0},{0,-1},{1,-1}},
	{{0,0},{0.1},{-1,0},{-1,-1}},
	{{0,0},{-1,0},{0,-1},{1,-1}},
	{{0,0},{0.1},{-1,0},{-1,-1}}
},
//3번블록:ㄹ자형
{
	{{0,0},{-1,-1},{0,-1},{1,0}},
	{{0,0},{-1,0},{-1,1},{0,-1}},
	{{0,0},{-1,1},{0,-1},{1,0}},
	{{0,0},{-1,0},{-1,1},{0,-1}}
},
//4번블록: ㄴ자형
{
	{{0,0},{-1,0},{1,0},{-1,-1}},
	{{0,0},{0,-1},{0,1},{-1,1}},
	{{0,0},{-1,0},{1,0},{1,1}},
	{{0,0},{0,-1},{0,1},{1,-1}}
},
//5번블록:ㄱ자형
{
	{{0,0},{1,0},{-1,0},{1,-1}},
	{{0,0},{0,1},{0,-1},{-1,-1}},
	{{0,0},{1,0},{-1,0},{-1,1}},
	{{0,0},{0,-1},{0,1},{1,1}}
},
//6번 블록:T자형
{
	{{0,0},{-1,0},{1,0},{0,1}},
	{{0,0},{0,1},{0,-1},{-1,-1}},
	{{0,0},{1,0},{-1,0},{-1,1}},
	{{0,0},{0,-1},{0,1},{1,1}}
}
};

void gotoXY(int x, int y) {
	COORD pos;
	pos.X = (SHORT)(x - 1);
	pos.Y = (SHORT)(y - 1);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void PrintBlock(int block, int startX, int startY) {
	//각블록 4칸 출력
	for (int i = 0; i < 4; i++) {
		int x = startX + Shape[block][0][i].x * 2; //블록 간격을 2로 설정해서 출력
		int y = startY + Shape[block][0][i].y;

		gotoXY(x, y);
		printf("■");
	}
}

int main(void) {
	//블록 7개를 순서대로 출력하는 테스트 코드
	for (int i = 0; i < 7;i++) {
		gotoXY(0, 3 + i * 4); //각블록을 아래로 간격을 두고 출력
		printf("블록 %d: ", i);
		PrintBlock(i, 15, 3 + i * 4); //각블록을 오른쪽으로 간격을 두고 출력
		printf("\n");
	}
}