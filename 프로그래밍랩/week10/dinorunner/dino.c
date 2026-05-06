#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#define DINO_BOTTOM_Y 12 //공룡이 서있는 Y좌표
#define TREE_BOTTOM_Y 20 //나무가 서있는 Y좌표
#define TREE_BOTTOM_X 45 

void GotoXY(int x, int y) {
	COORD Pos; //x,y좌표를 저장할 구조체 변수 선언
	Pos.X = 2 * x; //x좌표설정(문자 하나당 2칸씩 띄움)
	Pos.Y = y; //y좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //콘솔 커서 위치 설정
}

void DrawDino(int dinoY) {
	GotoXY(0, dinoY); //공룡의 위치로 이동
	static bool legflag = true; //다리 움직임을 위한 플래그 변수

	printf("        $$$$$$  \n");
	printf("       $$ $$$$$ \n");
	printf("       $$$$$$$$ \n");
	printf("$       $$$     \n");
	printf("$$      $$$$$   \n");
	printf("$$$    $$$$$    \n");
	printf(" $$   $$$$$$$$$ \n");
	printf("  $$$$$$$$$$$   \n");
	printf("   $$$$$$$$$    \n");
	
	if (legflag) {//다리움직임이 true일때
		printf("   $$     $$$    \n");
		printf("   $$$     $     \n");
		legflag = false; //다리움직임 플래그를 false로 변경하여 다음에는 다른 다리가 움직이도록 변경
	}
	else { //다리움직임이 false일때
		printf("   $$$    $      \n");
		printf("   $      $$$    \n");
		legflag = true;
	}
}

void DrawTree(int treeX) {
	GotoXY(treeX, TREE_BOTTOM_Y); //나무의 위치로 이동
	printf("$$$$"); //나무그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 1); //나무의 위치에서 한줄 아래로 이동
	printf(" $$ "); //나무그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 2); //나무의 위치에서 두줄 아래로 이동
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3); //나무의 위치에서 세줄 아래로 이동
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4); //나무의 위치에서 네줄 아래로 이동
	printf(" $$ ");
}

int GetKeyDown() {
	if (_kbhit() != 0) { //키보드입력이 있는지 확인
		int key = _getch();
		if (key == 224) { //방향키등의 특수키 입력이 있는 경우
			return _getch(); 
		}
		return key; //키보드입력이 있으면 해당키의 ASCII코드 반환
	}
	return 0; //키보드입력이 없으면 0 반환
}

int main() {
	bool isJumping = false; //공룡이 점프중인지 여부를 나타내는 변수
	bool isBottom = true; //공룡이 바닥에 있는지 여부를 나타내는 변수
	const int gravity = 3; //중력가속도(공룡이 떨어지는 속도)

	int dinoY = DINO_BOTTOM_Y; //공룡의 초기 y좌표 설정
	int treeX = TREE_BOTTOM_X; //나무의 초기 x좌표 설정
		
	while (true) { //게임루프시작
		if (GetKeyDown() == 72 && isBottom) {
			isJumping = true; //위쪽 방향키가 눌렸을때 점프 시작
			isBottom = false; //공룡이 바닥에 있지 않음
		}

		if (isJumping) {
			dinoY -= gravity; //공룡이 점프할때 y좌표 감소(반대로 생각해야한다!!!)
		}
		else {
			dinoY += gravity; //공룡이 떨어질때 y좌표증가(아래로 이동)
		}

		if (dinoY >= DINO_BOTTOM_Y) {
			dinoY = DINO_BOTTOM_Y; //공룡이 바닥에 닿으면 y좌표를 바닥으로 고정
			isBottom = true; //공룡이 바닥에 있음
		}

		if (dinoY <= 3) {
			isJumping = false; //공룡이 너무 높이 올라가면 점프 종료
		}

		treeX -= 2; //나무가 왼쪽으로 이동(속도조절가능)
		if(treeX <= 0) {
			treeX = TREE_BOTTOM_X; //나무가 화면 왼쪽 끝에 닿으면 초기위치로 리셋
		}

		DrawDino(dinoY); //공룡그리기
		DrawTree(treeX); //나무그리기
		Sleep(80); //게임루프의 속도를 조절하기위해 잠시 대기(80ms)
		system("cls"); //화면을 지우고 다음 프레임을 그리기 위해 콘솔 클리어
	}

	system("pause");
	return 0;
}