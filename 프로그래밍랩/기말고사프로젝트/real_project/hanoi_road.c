//하노이로드 기말고사 게임개발 프로젝트 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //system("cls") 사용하기 위해서 헤더 선언
#include <conio.h> //_getch입력함수 사용하기 위한 헤더
#include <time.h>

#define MAP_WIDTH 40 //게임 맵의 가로
#define MAP_HEIGHT 15 //게임 맵의 세로
#define CYCLE_COUNT 4 //맵에 등장할 오토바이의 숫자

typedef struct { //오토바이 구조체
	int x;
	int y;
	int speed;
}MotorCycle;

char playerName[20] = "지형"; //플레이어의 이름
int playerX = MAP_WIDTH / 2; //가로의 정중앙에 위치
int playerY = MAP_HEIGHT - 2; //맵의 마지막보다 한칸위
 
char map[MAP_HEIGHT][MAP_WIDTH];
MotorCycle motos[CYCLE_COUNT]; //오토바이를 CYCLE_COUNT개 만큼 생성하는 배열

//------------------------------함수 구성부---------------------------------------------------

void zeroMotorCycle() { //오토바이의 초기 위치 잡기
	motos[0].x = 5; motos[0].y = 3; motos[0].speed = 1; //3번라인 오토바이
	motos[1].x = 35; motos[1].y = 6; motos[1].speed = -1; //6번라인 오토바이
	motos[2].x = 10; motos[2].y = 9; motos[2].speed = 1; //9번라인 오토바이
	motos[3].x = 30; motos[3].y = 12; motos[3].speed = -1; //3번라인 오토바이
}

void moveMotorCycle() { //오토바이를 움직이게 하기
	for (int i = 0; i < CYCLE_COUNT; i++) {
		motos[i].x += motos[i].speed;
		if (motos[i].x >= MAP_WIDTH) {
			motos[i].x = 0; //맵의 오른쪽으로 나가면 왼쪽에서 들어오는것처럼 표현하기
		}
		if (motos[i].x < 0) {
			motos[i].x = MAP_WIDTH - 1; //맵의 왼쪽으로 나가면 오른쪽에서 들어오는것처럼 표현하기
		}
	}
}

//맵초기화 함수
void zeroMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (i == 0) { //맵의 첫번째 줄
				map[i][j] = 'p';
			}
			else if(i == (MAP_HEIGHT-1)) {
				map[i][j] = '#'; //맵의 마지막줄
			}
			else if (i % 3 == 0) {
				map[i][j] = '.'; //3번,6번,9번,12번 줄은 도로 표현하기
			}
			else {
				map[i][j] = ' '; //나머지는 빈칸으로 표시하기
			}

		}
	}
}

void print_Map(char map[MAP_HEIGHT][MAP_WIDTH]) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
//------------------------------ 시작 화면 함수 추가 -----------------------------------------
void show_TitleScreen() {
	system("cls");
	printf("\n\n\n");
	printf("      ####################################################\n");
	printf("      ##                                                ##\n");
	printf("      ##           [ 하 노 이  러  시 ]                 ##\n");
	printf("      ##         - 오토바이 사이에서 살아남기 -         ##\n");
	printf("      ##                                                ##\n");
	printf("      ####################################################\n");
	printf("\n");
	printf("                제작자: [이지형/2371214] \n\n");
	printf("          오토바이를 피해 무사히 길을 건너 쌀국수집에 가세요!\n");
	printf("\n\n");
	printf("              >> 게임을 시작하려면 [아무 키]나 누르세요... \n");

	// 사용자가 아무 키나 누를 때까지 기다리기
	_getch();

	//========== [이름 입력창 구현] =========
	printf("  하노이여행을 떠날 여행자의 성함을 입력해주세요.\n");
	printf("  이름 입력 (엔터) : ");
	scanf("%s", playerName);

	// 이름 입력 후 스토리 화면 갱신
	system("cls");
	printf("\n\n");
	printf("      ####################################################\n");
	printf("      ##           [ 하 노 이  러  시 ]                 ##\n");
	printf("      ####################################################\n\n");

	printf("  [STORY]\n");
	printf("  고된 대학 시험을 끝내고 베트남 하노이로 여행을 떠난 [%s]님.\n", playerName);
	printf("  인생 최고의 쌀국수 맛집이 눈앞에 있지만,\n");
	printf("  신호등 없는 도로 위엔 무시무시한 오토바이들이 폭주하고 있습니다!\n\n");
	printf("  \"과연 [%s]님은 치명적인 오토바이를 피해 쌀국수를 먹을 수 있을까요?\"\n", playerName);
	_getch();
}


//-----------------------------------------메인함수--------------------------------------

int main() {
	char map[MAP_HEIGHT][MAP_WIDTH];
	zeroMotorCycle();

	show_TitleScreen();

	while(1) {
		zeroMap(map);
		for (int i = 0; i < CYCLE_COUNT; i++)
			map[motos[i].y][motos[i].x] = 'O';
		map[playerY][playerX] = 'M';

		//오토바이와 충돌했을때 검사하기
		for (int i = 0; i < CYCLE_COUNT; i++) {
			if (playerY == motos[i].y && playerX == motos[i].x) {
				system("cls");
				printf("\n\n\n==============================================\n\n");
				printf("당신은 베트남의 횡단보도를 건너지 못했습니다!!\n");
				printf("프로그램을 종료하려면 아무키나 누르세요....\n");
				printf("\n\n==============================================\n");
				return 0;
			}
		}
		//쌀국수집 도달 검사하기
		if (playerY == 0) {
			system("cls");
			printf("\n\n쌀국수 맛집 도달 성공! 다음 맛집으로 이동합니다!");
			Sleep(1500);

			playerX = MAP_WIDTH / 2; //가로의 정중앙에 위치
			playerY = MAP_HEIGHT - 2; //맵의 마지막보다 한칸위
			continue;
		}

		//----------------------------------화면출력----------------------------------------
		system("cls");
		printf("=== [하노이에서 살아남기 : 베타버전] ===\n");
		printf(" WASD키를 눌러서 쌀국수집에 들어가게 해주세요\n");
		printf("=======(현재좌표 -X: %d, Y: %d)=======\n", playerX, playerY);
		print_Map(map);

		if (_kbhit()) { //keboardhit함수(키보드를 눌렀을대만 실행되게 하기
			//wasd키 입력
			char ch = _getch();
			if (ch == 'w' || ch == 'W') playerY--;
			if (ch == 's' || ch == 'S') playerY++;
			if (ch == 'a' || ch == 'A') playerX--;
			if (ch == 'd' || ch == 'D')playerX++;
			//맵밖으로 나가지 않도록 조건문 사용
			if (playerX < 0) playerX = 0;
			if (playerX >= MAP_WIDTH) playerX = MAP_WIDTH - 1;
			if (playerY < 0) playerY = 0;
			if (playerY >= MAP_HEIGHT) playerY = MAP_HEIGHT - 2;
		}
		moveMotorCycle();
		Sleep(100);
		//------------------------------화면출력----------------------------------------
	}
	return 0;
}