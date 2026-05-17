#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

#define MAP_WIDTH 78
#define MAP_HEIGHT 25

#define PLAYER_START_X 34
#define PLAYER_START_Y 22
#define MAX_CARS 10

// 1. 구조체 멤버명을 전공 서적 스타일로 명확하게 변경
typedef struct {
    int positionX;     // 가로 좌표
    int positionY;     // 세로 좌표
    int moveDirection; // 이동 방향 (1: 우측, -1: 좌측)
    int displayColor;  // 자동차 색상
} EntityCar;

EntityCar carList[MAX_CARS];

int currentX = PLAYER_START_X;
int currentY = PLAYER_START_Y;
int currentScore = 0;
int highScore = 0;       // 파일에서 불러올 최고 점수 변수
int currentLevel = 1;
int remainingLife = 3;

// 콘솔 커서 제어 함수
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 화면 깜빡임 및 커서 제거
void initConsoleSettings() {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    // 콘솔 창 크기 고정
    system("mode con cols=105 lines=40");
}

void setDisplayColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 2. 최고 점수를 파일에서 읽어오고 저장하는 파일 입출력 함수 (가산점 치트키 ⭐)
void loadHighScore() {
    FILE* file = fopen("highscore.dat", "rb");
    if (file != NULL) {
        fread(&highScore, sizeof(int), 1, file);
        fclose(file);
    }
    else {
        highScore = 500; // 파일이 없을 때 기본 초기값
    }
}

void saveHighScore() {
    if (currentScore > highScore) {
        highScore = currentScore;
    }
    FILE* file = fopen("highscore.dat", "wb");
    if (file != NULL) {
        fwrite(&highScore, sizeof(int), 1, file);
        fclose(file);
    }
}

// 3. 하드코딩 대신 난수(rand)를 이용한 자동차 초기화 알고리즘 ⭐
void initCarData() {
    int targetRows[4] = { 4, 7, 16, 19 }; // 자동차들이 다닐 도로 Y축 번호
    int rowColors[4] = { 13, 6, 14, 12 };  // 도로별 자동차 색상 기본값

    for (int i = 0; i < MAX_CARS; i++) {
        int rowIndex = i % 4; // 4개의 도로에 골고루 분배

        carList[i].positionY = targetRows[rowIndex];
        // 자동차들이 서로 겹치지 않게 무작위 가로 위치 설정
        carList[i].positionX = 5 + (rand() % 15) + (i * 6);

        // 도로마다 방향을 다르게 설정 (0, 2번 도로는 우측, 1, 3번 도로는 좌측)
        if (rowIndex == 0 || rowIndex == 2) {
            carList[i].moveDirection = 1;
        }
        else {
            carList[i].moveDirection = -1;
        }

        carList[i].displayColor = rowColors[rowIndex];
    }
}

// 메인 UI 렌더링 함수
void drawGameInterface() {
    setDisplayColor(7);
    printf(" =============================================================================== ====================\n");
    printf(" |======================== 길건너 친구들 - 콘솔 버전 =========================|                    |\n");
    printf(" |                                                                            | [ SCORE ]          |\n");

    setDisplayColor(10);
    printf(" |  ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^        목적지        ^ ^ ^ ^ ^ ^ ^ ^ ^ ^  ");
    setDisplayColor(14);
    printf("|      %05d       |\n", currentScore);

    setDisplayColor(7);
    printf(" |----------------------------------------------------------------------------|--------------------|\n");
    printf(" |                                                                            | [ BEST ]           |\n");
    printf(" |                                                                            |                    |\n");

    setDisplayColor(10);
    printf(" |============================================================================");
    setDisplayColor(14);
    printf("|      %05d       |\n", highScore);

    setDisplayColor(7);
    printf(" |                                                                            |--------------------|\n");
    printf(" |                                                                            | [ LEVEL ]          |\n");
    printf(" |                                                                            |                    |\n");

    setDisplayColor(10);
    printf(" |============================================================================");
    setDisplayColor(11);
    printf("|         %d          |\n", currentLevel);

    setDisplayColor(7);
    printf(" |                                                                            |--------------------|\n");
    setDisplayColor(11);
    printf(" | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ");
    setDisplayColor(7);
    printf("| [ LIFE ]           |\n");
    printf(" |                                                                            |                    |\n");

    setDisplayColor(6);
    printf(" |         =====                 =====                 =====                  ");
    setDisplayColor(12);
    if (remainingLife == 3)      printf("|       ♥ ♥ ♥        |\n");
    else if (remainingLife == 2) printf("|       ♥ ♥          |\n");
    else if (remainingLife == 1) printf("|       ♥            |\n");
    else                         printf("|                    |\n");

    setDisplayColor(11);
    printf(" | ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ");
    setDisplayColor(7);
    printf("|--------------------|\n");

    setDisplayColor(10);
    printf(" |============================================================================");
    setDisplayColor(7);
    printf("| [ CONTROLS ]       |\n");
    printf(" |                                                                            |                    |\n");
    printf(" |                                                                            | W : 위로           |\n");

    setDisplayColor(10);
    printf(" |============================================================================");
    setDisplayColor(7);
    printf("| A : 왼쪽           |\n");
    printf(" |                                                                            | S : 아래로         |\n");
    printf(" |                                                                            | D : 오른쪽         |\n");

    setDisplayColor(2);
    printf(" | . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ");
    setDisplayColor(7);
    printf("| Q : 종료           |\n");
    printf(" |                                                                            |--------------------|\n");

    setDisplayColor(2);
    printf(" | . . . . . . . . . . . . . . . ");
    setDisplayColor(14);
    printf("     (^^)     ");
    setDisplayColor(2);
    printf(". . . . . . . . . . . ");
    setDisplayColor(7);
    printf("| [ STATUS ]         |\n");

    setDisplayColor(2);
    printf(" | . . . . . . . . . . . . . . . ");
    setDisplayColor(14);
    printf("      ||      ");
    setDisplayColor(2);
    printf(". . . . . . . . . . . ");
    setDisplayColor(7);
    printf("|                    |\n");

    setDisplayColor(2);
    printf(" | . . . . . . . . . . . . . . . ");
    setDisplayColor(14);
    printf("     /||\\\\     ");
    setDisplayColor(2);
    printf(". . . . . . . . . . . ");
    setDisplayColor(10);
    printf("| 게임 진행 중...   |\n");

    setDisplayColor(2);
    printf(" |                                 출발지                                   ");
    setDisplayColor(7);
    printf("|                    |\n");

    setDisplayColor(7);
    printf(" =============================================================================== ====================\n\n");
    printf(" [ 게임 방법 ] WASD 키로 이동하여 자동차를 피해 목적지까지 가세요! (Q: 종료)\n");
}

void drawActiveCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        gotoxy(carList[i].positionX, carList[i].positionY);
        setDisplayColor(carList[i].displayColor);
        printf("[=]");
    }
}

void erasePrevCars() {
    for (int i = 0; i < MAX_CARS; i++) {
        gotoxy(carList[i].positionX, carList[i].positionY);
        printf("   ");
    }
}

void updateCarPositions() {
    for (int i = 0; i < MAX_CARS; i++) {
        carList[i].positionX += carList[i].moveDirection;

        // 화면 경계 예외 처리 코드 최적화
        if (carList[i].positionX > 68) carList[i].positionX = 2;
        if (carList[i].positionX < 2)  carList[i].positionX = 68;
    }
}

void drawPlayerCharacter() {
    gotoxy(currentX, currentY);
    setDisplayColor(14);
    printf("(^_^)");
}

void erasePrevPlayer() {
    gotoxy(currentX, currentY);
    printf("     ");
}

int checkCarCollision() {
    for (int i = 0; i < MAX_CARS; i++) {
        if (currentY == carList[i].positionY &&
            currentX >= carList[i].positionX - 1 &&
            currentX <= carList[i].positionX + 2) {
            return 1;
        }
    }
    return 0;
}

void resetPlayerPosition() {
    currentX = PLAYER_START_X;
    currentY = PLAYER_START_Y;
}

int main(void) {
    char inputKey;
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));

    initConsoleSettings();
    loadHighScore();  // 게임 시작 시 최고 점수 파일 불러오기
    initCarData();    // 무작위 자동차 생성
    drawGameInterface();

    while (1) {
        erasePrevCars();
        erasePrevPlayer();

        updateCarPositions();

        // 사용자 입력 비동기 처리
        if (_kbhit()) {
            inputKey = _getch();

            if (inputKey == 'w' || inputKey == 'W')      currentY--;
            else if (inputKey == 's' || inputKey == 'S') currentY++;
            else if (inputKey == 'a' || inputKey == 'A') currentX -= 2;
            else if (inputKey == 'd' || inputKey == 'D') currentX += 2;
            else if (inputKey == 'q' || inputKey == 'Q') break;
        }

        // 플레이어 벽 뚫기 방지 예외 처리
        if (currentX < 2)  currentX = 2;
        if (currentX > 68) currentX = 68;
        if (currentY > 22) currentY = 22;

        // 목적지 정상 도착 처리
        if (currentY <= 2) {
            currentScore += 100;
            currentLevel++;
            saveHighScore(); // 최고 점수 갱신 시 자동 파일 저장

            resetPlayerPosition();

            // 실시간 상단 스코어보드 수치 갱신
            gotoxy(82, 3); setDisplayColor(14); printf("%05d", currentScore);
            gotoxy(82, 6); setDisplayColor(14); printf("%05d", highScore);
            gotoxy(82, 9); setDisplayColor(11); printf("%d", currentLevel);
        }

        // 자동차 충돌 감지 처리
        if (checkCarCollision()) {
            remainingLife--;
            resetPlayerPosition();

            // 라이프 UI 하트 개수 차감 반영
            gotoxy(82, 15);
            setDisplayColor(12);
            if (remainingLife == 3)      printf("♥ ♥ ♥ ");
            else if (remainingLife == 2) printf("♥ ♥   ");
            else if (remainingLife == 1) printf("♥     ");
            else {
                gotoxy(30, 33);
                setDisplayColor(12);
                printf("GAME OVER");
                saveHighScore(); // 죽었을 때 최종 저장
                break;
            }
        }

        drawActiveCars();
        drawPlayerCharacter();

        // 레벨이 올라갈수록 게임 속도가 미세하게 빨라지는 동적 난이도 구현 ⭐
        int levelSpeed = 100 - (currentLevel * 5);
        if (levelSpeed < 30) levelSpeed = 30; // 최대 속도 제한 예외처리

        Sleep(levelSpeed);
    }

    // 의미 없이 남아있던 하단 유령 코드를 깔끔하게 정리 완료
    system("cls");
    printf("\n 게임을 종료합니다. 수고하셨습니다!\n");
    return 0;
}