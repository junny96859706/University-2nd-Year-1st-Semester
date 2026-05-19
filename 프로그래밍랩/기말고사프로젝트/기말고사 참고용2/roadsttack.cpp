// 하노이로드 기말고사 게임개발 프로젝트 - 3단계 옴니버스 합체 버전
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // system("cls"), Sleep, Beep 사용을 위한 헤더
#include <conio.h>   // _getch, _kbhit 사용을 위한 헤더
#include <time.h>    // rand, clock 사용을 위한 헤더
#include <string.h>  // strcmp 사용을 위한 헤더

#define MAP_WIDTH 40  // 게임 맵의 가로
#define MAP_HEIGHT 15 // 게임 맵의 세로
#define CYCLE_COUNT 4 // 맵에 등장할 오토바이의 숫자

typedef struct { // 오토바이 구조체
	int x;
	int y;
	int speed;
} MotorCycle;

// [전역 변수 설정]
char playerName[20] = "지형";
int playerX = MAP_WIDTH / 2;
int playerY = MAP_HEIGHT - 2;
char map[MAP_HEIGHT][MAP_WIDTH];
MotorCycle motos[CYCLE_COUNT];

//------------------------------ 함수 구성부 ---------------------------------------------------
void zeroMotorCycle() { // 오토바이의 초기 위치 랜덤화
	motos[0].x = rand() % MAP_WIDTH; motos[0].y = 3;  motos[0].speed = 1;
	motos[1].x = rand() % MAP_WIDTH; motos[1].y = 6;  motos[1].speed = -1;
	motos[2].x = rand() % MAP_WIDTH; motos[2].y = 9;  motos[2].speed = 1;
	motos[3].x = rand() % MAP_WIDTH; motos[3].y = 12; motos[3].speed = -1;
}

void moveMotorCycle() { // 오토바이를 움직이게 하기
	for (int i = 0; i < CYCLE_COUNT; i++) {
		motos[i].x += motos[i].speed;
		if (motos[i].x >= MAP_WIDTH)  motos[i].x = 0;
		if (motos[i].x < 0)           motos[i].x = MAP_WIDTH - 1;
	}
}

void zeroMap(char map[MAP_HEIGHT][MAP_WIDTH]) { // 맵 초기화
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (i == 0)                   map[i][j] = 'p'; // 쌀국수집 라인
			else if (i == (MAP_HEIGHT - 1)) map[i][j] = '#'; // 시작 라인
			else if (i % 3 == 0)          map[i][j] = '.'; // 도로 표현
			else                          map[i][j] = ' ';
		}
	}
}

void print_Map(char map[MAP_HEIGHT][MAP_WIDTH]) { // 맵 출력
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void show_TitleScreen() { // 1단계 진입 전 시작 및 스토리 화면
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
	_getch();

	printf("  하노이여행을 떠날 여행자의 성함을 입력해주세요.\n");
	printf("  이름 입력 (엔터) : ");
	scanf("%s", playerName);
	while (getchar() != '\n'); // 입력 버퍼 비우기

	system("cls");
	printf("\n\n");
	printf("      ####################################################\n");
	printf("      ##           [ 하 노 이  러  시 ]                 ##\n");
	printf("      ####################################################\n\n");
	printf("  [STORY]\n");
	printf("  고된 대학 시험을 끝내고 베트남 하노이로 여행을 떠난 [%s]님.\n", playerName);
	printf("  인생 최고의 쌀