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
	printf("  인생 최고의 쌀국수 맛집이 눈앞에 있지만,\n");
	printf("  신호등 없는 도로 위엔 무시무시한 오토바이들이 폭주하고 있습니다!\n\n");
	printf("  \"과연 [%s]님은 치명적인 오토바이를 피해 쌀국수를 먹을 수 있을까요?\"\n\n", playerName);
	printf("              >> 1단계 시작하려면 [아무 키]나 누르세요... \n");
	_getch();
}

//----------------------------------------- 메인함수 --------------------------------------
int main() {
	srand((unsigned int)time(NULL));
	char map[MAP_HEIGHT][MAP_WIDTH];
	zeroMotorCycle();

	// 타이틀 및 이름 입력 시스템 구동
	show_TitleScreen();

	// =================================================================================
	// [STAGE 1] 하노이 러시아워 (오토바이 피하기)
	// =================================================================================
	while (1) {
		zeroMap(map);
		for (int i = 0; i < CYCLE_COUNT; i++)
			map[motos[i].y][motos[i].x] = 'O';
		map[playerY][playerX] = 'M';

		// 충돌 검사
		for (int i = 0; i < CYCLE_COUNT; i++) {
			if (playerY == motos[i].y && playerX == motos[i].x) {
				system("cls");
				printf("\n\n💥 교통사고 발생! 당신은 횡단보도를 건너지 못했습니다.\n");
				printf("게임이 종료됩니다. 아무키나 누르세요...\n");
				_getch();
				return 0;
			}
		}

		// 1단계 클리어 조건 (쌀국수집 라인 도착)
		if (playerY == 0) {
			system("cls");
			printf("\n\n🎉 [STAGE 1 클리어] 무사히 도로를 건너 가게 문을 열었습니다!\n");
			printf("다음 단계로 이동합니다... 잠시만 기다려주세요.\n");
			Sleep(2500);
			break; // STAGE 1 루프를 탈출하여 STAGE 2로 진입! ⭐
		}

		system("cls");
		printf("=== [STAGE 1 : 하노이 러시아워] 여행자: %s ===\n", playerName);
		printf(" * 한글 입력 상태라면 [한/영] 키를 눌러 영어로 바꿔주세요! *\n");
		printf(" WASD 키를 움직여 도로 위쪽 맛집 'p' 라인으로 전진하세요!\n");
		printf("=======(현재좌표 -X: %d, Y: %d)=======\n", playerX, playerY);
		print_Map(map);

		if (_kbhit()) {
			char ch = _getch();
			if (ch == 0 || ch == -32) _getch(); // 한글 버퍼 예외처리

			if (ch == 'w' || ch == 'W') playerY--;
			if (ch == 's' || ch == 'S') playerY++;
			if (ch == 'a' || ch == 'A') playerX--;
			if (ch == 'd' || ch == 'D') playerX++;

			if (playerX < 0) playerX = 0;
			if (playerX >= MAP_WIDTH) playerX = MAP_WIDTH - 1;
			if (playerY < 0) playerY = 0;
			if (playerY >= MAP_HEIGHT) playerY = MAP_HEIGHT - 2;
		}
		moveMotorCycle();
		Sleep(100);
	}

	// =================================================================================
	// [STAGE 2] 쌀국수 주문하기 (문자열 매칭 타이핑)
	// =================================================================================
	system("cls");
	char quiz[20] = "Pho Bo";
	char input[20];
	printf("\n=== [STAGE 2 : 쌀국수 주문하기] ===\n");
	printf("가게에 들어섰지만 직원이 베트남어로 빠르게 물어봅니다!\n");
	printf("제한시간 5초 안에 아래 제시어를 정확히 타이핑하여 주문을 완료하세요.\n\n");
	printf("👉 주문할 메뉴 제시어: [%s]\n\n", quiz);
	printf("입력 후 엔터 : ");

	clock_t start_time = clock(); // 타이머 가동
	scanf("%s", input);
	clock_t end_time = clock();

	double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\n주문 소요 시간: %.2f초\n", duration);

	if (duration > 5.0) {
		printf("❌ [시간 초과] 점원이 알아듣지 못하고 다른 손님에게 가버렸습니다. (게임오버)\n");
		_getch(); _getch();
		return 0;
	}
	else if (strcmp(quiz, input) != 0) {
		printf("❌ [주문 실패] 오타가 났습니다! 베트남에 없는 엉뚱한 메뉴를 말했습니다. (게임오버)\n");
		_getch(); _getch();
		return 0;
	}

	printf("\n🎉 [STAGE 2 클리어] 정확하게 주문했습니다! 주방에서 음식이 나옵니다.\n");
	printf("음식을 들고 자리로 이동합니다... 잠시만 기다려주세요.\n");
	Sleep(2500);

	// =================================================================================
	// [STAGE 3] 국물 안 쏟고 자리 잡기 (실시간 밸런스 게이지 액션)
	// =================================================================================
	int gauge = 10;
	int max_gauge = 20;
	int walk_count = 0;
	int target_walk = 20;

	while (1) {
		system("cls");
		printf("\n=== [STAGE 3 : 뜨거운 국물 들고 자리 잡기] ===\n");
		printf(" 손님이 꽉 찬 매장! 국물이 넘치지 않게 균형을 잡으며 빈자리로 가세요.\n");
		printf(" ⚠️ 가만히 있으면 균형이 깨집니다! A, D 키를 연타하여 조작하세요!\n");
		printf(" 🍜 목적지까지 남은 거리: %d / %d 걸음\n\n", walk_count, target_walk);

		// 게이지 바 출력
		printf("쏟아짐 위험 [");
		for (int i = 0; i <= max_gauge; i++) {
			if (i == gauge) printf("|");
			else if (i == 0 || i == max_gauge) printf("X");
			else printf(" ");
		}
		printf("]\n\n");

		// 탈락 조건
		if (gauge <= 0 || gauge >= max_gauge) {
			printf("💥 으아악! 손님과 부딪혀 뜨거운 국물을 쏟았습니다! (게임오버)\n");
			_getch();
			return 0;
		}

		// 게임 최종 클리어 조건
		if (walk_count >= target_walk) {
			break;
		}

		// 무작위 흔들림 알고리즘
		int shake = (rand() % 4) - 2;
		if (shake >= 0) shake += 1;
		gauge += shake;

		// 유저 키 입력 처리 (입력할 때만 전진)
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'a' || ch == 'A') { gauge -= 3; walk_count++; }
			if (ch == 'd' || ch == 'D') { gauge += 3; walk_count++; }
		}
		Sleep(150);
	}

	// =================================================================================
	// [GAME CLEAR] 최종 엔딩 화면
	// =================================================================================
	system("cls");
	printf("\n\n\n");
	printf("      ####################################################\n");
	printf("      ##                                                ##\n");
	printf("      ##        🎉 하노이 쌀국수 원정 성공! 🎉         ##\n");
	printf("      ##                                                ##\n");
	printf("      ####################################################\n\n");
	printf("  [%s]님은 무시무시한 러시아워를 뚫고, 현지인 주문을 완벽하게 해낸 뒤,\n", playerName);
	printf("  단 한 방울의 국물도 쏟지 않고 테이블에 앉는 데 성공했습니다!\n\n");
	printf("  진하고 따뜻한 최고의 소고기 쌀국수(Pho Bo)를 맛보며 여행을 즐깁니다.\n");
	printf("  ~ HAPPY ENDING ~\n\n");
	printf("====================================================================\n");
	printf("  플레이 해주셔서 감사합니다. [아무 키]나 누르면 프로그램이 종료됩니다.\n");

	_getch();
	return 0;
}