#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> 
#include <conio.h> 
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAP_WIDTH 60 
#define MAP_HEIGHT 20
#define UI_WIDTH 24
#define CYCLE_COUNT 6 
#define OBSTACLE_COUNT 6

typedef struct {
    int x;
    int y;
    int speed;
    int baseSpeed;
} MotorCycle;

typedef struct {
    int x;
    int y;
} Obstacle;

char playerName[20] = "지형";
int playerLife = 3;
int playerX = MAP_WIDTH / 2;
int playerY = MAP_HEIGHT - 2;
char map[MAP_HEIGHT][MAP_WIDTH];
MotorCycle motos[CYCLE_COUNT];
Obstacle obs[OBSTACLE_COUNT];
int currentRound = 1;
int debugMode = 0; //디버그모드

// 커서
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 색상표기
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 화면진동
void triggerScreenShake() {
    HWND hwnd = GetForegroundWindow();
    RECT rect;
    if (hwnd != NULL) {
        GetWindowRect(hwnd, &rect);
        int x = rect.left; int y = rect.top;
        int width = rect.right - rect.left; int height = rect.bottom - rect.top;
        for (int i = 0; i < 4; i++) {
            MoveWindow(hwnd, x + 15, y, width, height, TRUE); 
            Sleep(25);
            MoveWindow(hwnd, x - 15, y, width, height, TRUE); 
            Sleep(25);
        }
        MoveWindow(hwnd, x, y, width, height, TRUE);
    }
}

// 효과음 제어
void playSound(int type) {
    if (type == 1) 
        Beep(600, 30);
    if (type == 2) 
        Beep(150, 400);
    if (type == 3) {
        Beep(523, 100); 
        Beep(659, 100); 
        Beep(784, 100); 
        Beep(1046, 200);
    }
    if (type == 4) {
        Beep(523, 100);
        Beep(587, 100); 
        Beep(659, 100); 
        Beep(698, 100);
        Beep(784, 100);
        Beep(880, 100); 
        Beep(988, 100); 
        Beep(1046, 400);
    }
    if (type == 5) 
        Beep(300, 100);
    if (type == 6) {
        Beep(300, 200); 
        Beep(300, 200);
    }
}

// 오토바이 초기화
void zeroMotorCycle() {
    motos[0].x = 5;  motos[0].y = 3;  motos[0].baseSpeed = 1;
    motos[1].x = 50; motos[1].y = 5;  motos[1].baseSpeed = -1;
    motos[2].x = 10; motos[2].y = 8;  motos[2].baseSpeed = 2;
    motos[3].x = 40; motos[3].y = 11; motos[3].baseSpeed = -1;
    motos[4].x = 20; motos[4].y = 14; motos[4].baseSpeed = -2;
    motos[5].x = 15; motos[5].y = 17; motos[5].baseSpeed = 1;

    for (int i = 0; i < CYCLE_COUNT; i++) motos[i].speed = motos[i].baseSpeed;
}

//고정 장애물 초기화
void zeroObstacle() {
    obs[0].x = MAP_WIDTH / 2;     
    obs[0].y = 15;
    obs[1].x = MAP_WIDTH / 2 - 5; 
    obs[1].y = 12;
    obs[2].x = MAP_WIDTH / 2 + 8; 
    obs[2].y = 9;
    obs[3].x = 15;                
    obs[3].y = 6;
    obs[4].x = 45;                
    obs[4].y = 6;
    obs[5].x = MAP_WIDTH / 2;     
    obs[5].y = 2;
}

// 라운드별 속도 가속
void updateDifficulty() {
    for (int i = 0; i < CYCLE_COUNT; i++) {
        if (motos[i].baseSpeed > 0) motos[i].speed = motos[i].baseSpeed + (currentRound - 1);
        else motos[i].speed = motos[i].baseSpeed - (currentRound - 1);
    }
}

// 오토바이 이동
void moveMotorCycle() {
    for (int i = 0; i < CYCLE_COUNT; i++) {
        motos[i].x += motos[i].speed;
        if (motos[i].x >= MAP_WIDTH - 7) motos[i].x = 1;
        if (motos[i].x < 1) motos[i].x = MAP_WIDTH - 8;
    }
}

void zeroMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == 0) map[i][j] = 'p';
            else if (i == (MAP_HEIGHT - 1)) map[i][j] = '#';
            else if (i == 4 || i == 10 || i == 16) map[i][j] = '=';
            else if (i == 7 || i == 13) map[i][j] = '~';
            else map[i][j] = ' ';
        }
    }
    for (int i = 0; i < OBSTACLE_COUNT; i++) map[obs[i].y][obs[i].x] = 'X';
}

// 장애물 충돌
int checkObstacle(int nextX, int nextY) {
    for (int i = 0; i < OBSTACLE_COUNT; i++) {
        if (nextY == obs[i].y && (nextX + 4 >= obs[i].x && nextX <= obs[i].x + 2)) return 1;
    }
    return 0;
}

// 화면 출력 함수
void print_Map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    gotoxy(0, 5);
    int uiLine = 0;

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j] == 'O') {
                int speedDir = 1;
                for (int m = 0; m < CYCLE_COUNT; m++) { if (motos[m].y == i) speedDir = motos[m].speed; }
                setColor(12);
                if (speedDir > 0) { printf("~[oNo]=>"); j += 7; }
                else { printf("<= [oNo]~"); j += 7; }
                setColor(7);
            }
            else if (map[i][j] == 'X') {
                setColor(13); printf("[X]"); j += 2; setColor(7);
            }
            else if (map[i][j] == 'M') {
                setColor(10); printf("(^o^)"); j += 4; setColor(7);
            }
            else if (map[i][j] == 'p') {
                setColor(14); printf("%c", map[i][j]); setColor(7);
            }
            else printf("%c", map[i][j]);
        }

        printf("|");
        if (uiLine == 0)      printf(" [ PILOT INFO ]         |");
        else if (uiLine == 1) printf("  RIDER: %s님           ", playerName);
        else if (uiLine == 2) {
            printf("  LIFE: ");
            for (int k = 0; k < 3; k++) {
                if (k < playerLife) { setColor(12); printf("* "); setColor(7); }
                else printf("  ");
            }
            printf("       ");
        }
        else if (uiLine == 4)  printf("------------------------|");
        else if (uiLine == 5)  printf(" [ STAGE INFO ]         |");
        else if (uiLine == 6)  printf("  STAGE 1 / 3           |");
        else if (uiLine == 7)  printf("  ROUND : %d / 3         ", currentRound);
        else if (uiLine == 8)  printf("------------------------| ");
        if (debugMode == 1) {
            if (uiLine == 9)       printf(" [ DEBUG ACTIVE ]       |");
            else if (uiLine == 10) { setColor(14); printf("  무적 모드 가동 중     "); setColor(7); }
        }
        else {
            if (uiLine == 9)       printf(" [ CONTROLS ]           |");
            else if (uiLine == 10) printf("  W,A,S,D : 이동 제어   |");
        }
        if (uiLine == 12)      printf("------------------------|");
        else if (uiLine == 13) printf(" [ STATUS MESSAGE ]     |");
        else if (uiLine == 14) {
            if (currentRound == 3) printf("  폭주족 최종 라운드!!  ");
            else if (playerY == 8 || playerY == 14) printf("  과속 차선 진입 주의!  ");
            else printf("  공사 표지판 우회하기  ");
        }
        else if (uiLine != 9 && uiLine != 10) printf("                        |");

        printf("\n");   uiLine++;
    }
    for (int j = 0; j < MAP_WIDTH; j++) printf("=");
    printf("==========================\n");
}

void show_TitleScreen() {
    int choice = 1;
    while (1) {
        system("cls");
        printf("\n");
        printf("      ====================================================================\n");
        printf("      * _   _    _    _   _  ___   _      ____  _   _ ____  _   _    *\n");
        printf("      * | | | |  / \\  | \\ | |/ _ \\ | |    |  _ \\| | | / ___|| | | |   *\n");
        printf("      * | |_| | / _ \\ |  \\| | | | || |    | |_) | | | \\___ \\| |_| |   *\n");
        printf("      * |  _  |/ ___ \\| |\\  | |_| || |    |  _ <| |_| |___) |  _  |   *\n");
        printf("      * |_| |_/_/   \\_\\_| \\_|\\___/ |_|    |_| \\_\\\\___/|____/|_| |_|   *\n");
        printf("      ====================================================================\n");
        printf("                        DEVELOPED BY. COMPUTER ENG. JI-HYEONG             \n\n\n");

        printf("                     ------------------------------------\n");
        if (choice == 1) { printf("                     |   "); setColor(10); printf("->  1. GAME START               "); setColor(7); printf("|\n"); }
        else printf("                     |      1. GAME START               |\n");
        if (choice == 2) { printf("                     |   "); setColor(14); printf("->  2. HOW TO PLAY (MANUAL)     "); setColor(7); printf("|\n"); }
        else printf("                     |      2. HOW TO PLAY (MANUAL)     |\n");
        if (choice == 3) { printf("                     |   "); setColor(12); printf("->  3. GAME EXIT                "); setColor(7); printf("|\n"); }
        else printf("                     |      3. GAME EXIT                |\n");
        printf("                     ------------------------------------\n\n");

        printf("                 원하는 메뉴 번호 입력 후 Enter -> ");
        int input = 0;
        if (scanf("%d", &input) != 1) { while (getchar() != '\n'); continue; }
        if (input >= 1 && input <= 3) choice = input;
        else continue;

        if (choice == 1) {
            system("cls");
            printf("\n\n  [ 채점관 및 편의성 전용 시스템 설정!! ]\n");
            printf("  교수님 채점 편의를 위한 무적 모드를 켜시겠습니까? (1: 켜기 / 0: 일반 진행) -> ");
            if (scanf("%d", &debugMode) != 1) { while (getchar() != '\n'); debugMode = 0; }

            if (debugMode == 1) {
                playerLife = 999;
                printf("\n  >> 무적 모드가 활성화되었습니다. 낙오 없이 끝까지 채점 가능합니다. <<\n");
                Sleep(1500);
            }

            system("cls");
            printf("\n\n  [ CHARACTER REGISTRATION ]\n");
            printf("  플레이어의 이름을 입력해 주세요.\n");
            printf("  -> NAME : ");   scanf("%s", playerName);

            system("cls");
            printf("\n\n      ====================================================\n");
            printf("      ##           [ SYSTEM : HANOI RUSH ]              ##\n");
            printf("      ====================================================\n\n");
            printf("  하노이로 여행을 떠난 컴퓨터공학과 [%s] 학생.\n", playerName);
            printf("  인생 쌀국수 맛집이 눈앞에 있지만 오토바이가 너무 많습니다.\n");
            printf("  총 3번 길을 무사히 건너야 식당 내부로 입장할 수 있습니다!\n");
            printf("  중간에 놓인 자홍색 공사 표지판[X]은 통과할 수 없으니 우회하세요.\n\n");
            printf("  >> 아무 키나 누르면 게임을 시작합니다.");
            _getch(); break;
        }
        else if (choice == 2) {
            system("cls");
            printf("\n\n      =================== [ GAME MANUAL ] ===================\n\n");
            printf("  - W, A, S, D 이동 및 방향 제어\n");
            printf("  - (^o^) 플레이어 캐릭터 / [X] 이동 불가 공사 표지판\n\n");
            printf("  >> 타이틀로 돌아가려면 아무 키나 누르세요... "); _getch();
        }
        else if (choice == 3) { system("cls"); printf("\n\n 게임을 종료합니다. 감사합니다.\n\n"); exit(0); }
    }
}

//----------------------------------------------------------------------------------------------------//

int main() {
    srand((unsigned int)time(NULL));
    zeroMotorCycle();
    zeroObstacle();

    show_TitleScreen();
    system("cls");

 //--------------------------------STAGE 1 : 오토바이 피하기------------------------------------------

    int stage1_Success = 0;
    while (1) {
        zeroMap(map);
        for (int i = 0; i < CYCLE_COUNT; i++) map[motos[i].y][motos[i].x] = 'O';
        map[playerY][playerX] = 'M';

        for (int i = 0; i < CYCLE_COUNT; i++) {
            if (playerY == motos[i].y && (playerX + 4 >= motos[i].x && playerX <= motos[i].x + 6)) {
                playerLife--;
                playSound(2);
                triggerScreenShake();
                playerX = MAP_WIDTH / 2; playerY = MAP_HEIGHT - 2;

                if (playerLife <= 0) break;
            }
        }

        if (playerLife <= 0) break;

        if (playerY == 0) {
            if (currentRound < 3) {
                playSound(3); system("cls");
                printf("\n\n Round %d 클리어! 속도가 빨라집니다!\n", currentRound);
                Sleep(1500);
                currentRound++; updateDifficulty();
                playerX = MAP_WIDTH / 2; playerY = MAP_HEIGHT - 2;
            }
            else {
                playSound(3); system("cls");
                printf("\n\n STAGE 1 클리어 성공입니다! 오토바이를 뚫고 식당에 입장했습니다!\n");
                Sleep(2000);
                stage1_Success = 1;
                break;
            }
        }

        gotoxy(0, 0);
        printf("=== [STAGE 1 : 오토바이 피하기] ===\n");
        print_Map(map);

        if (_kbhit()) {
            char ch = _getch();
            int nextX = playerX; int nextY = playerY; int triedMove = 0;

            if (ch == 'w' || ch == 'W') { nextY--; triedMove = 1; }
            if (ch == 's' || ch == 'S') { nextY++; triedMove = 1; }
            if (ch == 'a' || ch == 'A') { nextX -= 3; triedMove = 1; }
            if (ch == 'd' || ch == 'D') { nextX += 3; triedMove = 1; }

            if (triedMove) {
                if (!checkObstacle(nextX, nextY)) { playerX = nextX; playerY = nextY; playSound(1); }
                else playSound(5);
            }

            if (playerX < 1) playerX = 1;
            if (playerX >= MAP_WIDTH - 5) playerX = MAP_WIDTH - 5;
            if (playerY < 0) playerY = 0;
            if (playerY >= MAP_HEIGHT - 1) playerY = MAP_HEIGHT - 2;
        }
        moveMotorCycle(); Sleep(50);
    }

    if (playerLife <= 0 || !stage1_Success) {
        system("cls");
        printf("\n\n 아쉽게도 쌀국수집에 도달하지 못하고 횡단보도를 건너지 못했습니다ㅠㅠ 게임을 종료합니다.\n");
        _getch(); 
        return 0;
    }

 // -----------------------------STAGE 2 : 5초 타임어택 주문하기------------------------------------------

    system("cls");
    printf("\n\n      ====================================================\n");
    printf("      ##        [ STAGE 2 안내문 ]         ##\n");
    printf("      ====================================================\n\n");
    printf("  축하합니다! 무사히 오토바이 지옥을 뚫고 식당 문을 열었습니다.\n\n");
    printf("  [ STAGE 2 규칙 설명 ]\n");
    printf("  - 문을 열고 들어가면 점원이 주문을 받기 위해 대기하고 있습니다.\n");
    printf("  - 화면에 나타나는 베트남어 제시어를 신속하고 정확하게 입력해야 합니다.\n");
    printf("  - 입력 제한 시간은 [5초]이며 기회는 한번입니다!\n\n");
    if (debugMode == 1) {
        setColor(14);
        printf("  ※ 현재 무적 모드가 켜져 있어 실패해도 통과됩니다.\n\n"); 
        setColor(7);
    }
    printf("  >> 준비가 되었다면 [아무 키]나 눌러 주문을 시작해주세요...!");
    _getch();


    system("cls");
    char quiz[20] = "PhoBo";
    char input[20];
    clock_t start_time, end_time;
    double limit_time = 5.0;

    printf("\n  ===============================================================\n");
    printf("  ##        [ STAGE 2 : 하노이 명품 쌀국수 주문하기 ]          ##\n");
    printf("  ===============================================================\n\n");
    printf("         ( - )  <  \"어서 오십시오, 손님!\n          /||\\       5초 안에 정확히 주문하셔야 조리가 시작됩니다!\"\n");
    printf("          /  \\ \n       ============\n       |   V  V   | \n        \\________/   [ 최고의 소고기 쌀국수 대기 중 ]\n\n");
    printf("  ---------------------------------------------------------------\n");
    printf("    제시어  : "); setColor(13); printf("[%s]", quiz); setColor(7);
    if (debugMode == 1) printf(" (플레이어 상태: 무적 활성화)\n");
    else printf(" (남은 목숨: %d개)\n", playerLife);
    printf("  ---------------------------------------------------------------\n\n");
    printf("  -> 주문 입력 : ");

    start_time = clock();
    scanf("%19s", input); // scanf 버퍼 오버플로우 방어 코드 적용
    end_time = clock();

    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n  - 주문 소요 시간: "); 
    setColor(11); 
    printf("%.2f초", total_time); 
    setColor(7); 
    printf(" (제한시간: 5.00초)\n");

    int stage2_Success = 0;
    if (total_time > limit_time) {
        if (debugMode == 1) {
            setColor(14); 
            printf("\n  [알림] 시간 초과되었으나 무적 모드로 Stage 2를 패스합니다.\n"); 
            setColor(7);
            stage2_Success = 1; 
            Sleep(2000);
        }
        else {
            setColor(12); 
            printf("\n  주문 실패: 시간이 초과되어 식당에서 쫓겨났습니다.\n"); 
            setColor(7);
            playSound(6); 
            triggerScreenShake();
        }
    }
    else if (strcmp(quiz, input) == 0) {
        setColor(10); 
        printf("\n  주문 성공! 주문이 정상적으로 주방에 접수되었습니다.\n"); 
        setColor(7);
        playSound(3); 
        Sleep(2000); 
        stage2_Success = 1;
    }
    else {
        if (debugMode == 1) {
            setColor(14); 
            printf("\n  [알림] 오타가 발생했으나 무적 모드로 Stage 2를 패스합니다.\n"); 
            setColor(7);
            stage2_Success = 1;
            Sleep(2000);
        }
        else {
            setColor(12); 
            printf("\n  주문 실패: 오타가 발생했습니다! 입력한 메뉴: [%s]\n", input); 
            setColor(7);
            playSound(6); 
            triggerScreenShake();
        }
    }

    if (!stage2_Success) {
        _getch();
        return 0;
    }


 // -------------------------- STAGE 3 : 국물 들고 자리 잡기 균형 게임----------------------------------------

    int gauge = 10; 
    int max_gauge = 20;
    int walk_count = 0; int target_walk = 30;

    while (1) {
        system("cls");
        printf("\n  ===============================================================\n");
        printf("  ##        [ STAGE 3 : 뜨거운 국물 들고 자리 잡기 ]          ##\n");
        printf("  ===============================================================\n\n");
        printf("  손님들 사이를 지나 빈자리까지 국물이 넘치지 않게 균형을 잡으세요!\n\n");

        printf("  -> 빈자리까지 남은 거리 : ["); setColor(14);
        for (int i = 0; i < target_walk; i++) {
            if (i < walk_count) 
                printf("=");
            else if (i == walk_count) 
                printf(">");
            else 
                printf(" ");
        }
        setColor(7); 
        printf("] (%d / %d 걸음)\n\n", walk_count, target_walk);

        printf("        [!] 왼쪽으로 쏟아짐주의             오른쪽으로 쏟아짐주의 [!]\n");
        printf("        -------------------------------------------------------\n        | ");
        for (int i = 0; i <= max_gauge; i++) {
            if (i == gauge) { 
                setColor(12); printf("O"); setColor(7); }
            else if (i == 0 || i == max_gauge) { 
                setColor(13); printf("X"); setColor(7); }
            else if (i == 10) { 
                setColor(10); printf("|"); setColor(7); }
            else printf(".");
        }
        printf(" |\n        -------------------------------------------------------\n");
        printf("         [A키] 왼쪽 균형 잡기            [D키] 오른쪽 균형 잡기\n\n");

        if (gauge <= 0 || gauge >= max_gauge) {
            if (debugMode == 1) {
                setColor(14); 
                printf("  [알림] 국물을 쏟았으나 중심을 강제 복구하여 계속 진행합니다!\n"); 
                setColor(7);
                gauge = 10;
                Sleep(1000);
            }
            else {
                setColor(12); 
                printf("  게임 오버! 균형이 무너져 뜨거운 국물을 쏟았습니다!\n"); 
                setColor(7);
                playSound(2); 
                triggerScreenShake(); 
                break;
            }
        }

        if (walk_count >= target_walk) {
            setColor(10); 
            printf("  최종 클리어! 무사히 식탁에 자리를 잡았습니다.\n");
            printf("  플레이어님은 하노이의 쌀국수를 맛있게 식사하며 여정을 마무리합니다!\n"); 
            setColor(7);
            playSound(4); 
            break;
        }

        int shake = (rand() % 3) - 1; gauge += shake;

        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') gauge -= 2;
            if (ch == 'd' || ch == 'D') gauge += 2;
            playSound(1);
        }
        walk_count++; Sleep(150);
    }

    system("cls");
    printf("\n\n");
    printf("      ====================================================================\n");
    printf("      * _____ _   _ _____ _____ _   _ _____ ___ _   _  ____        *\n");
    printf("      * |_   _| | | | ____| ____| \\ | |  _  |_ _| \\ | |/ ___|       *\n");
    printf("      * | | | |_| |  _| |  _| |  \\| | | | | | ||  \\| | |  _        *\n");
    printf("      * | | |  _  | |___| |___| |\\  | |_| | | || |\\  | |_| |       *\n");
    printf("      * |_| |_| |_|_____|_____|_| \\_|_____|___|_| \\_|\\____|       *\n");
    printf("      ====================================================================\n");
    printf("                 게임을 즐겨주셔서 감사합니다, %s 님!                     \n\n", playerName);

    setColor(14); 
    printf("                 (  )   (   )  (  )\n");
    printf("                     )   (    (   )\n");
    setColor(11); 
    printf("             .------------------------.\n");
    printf("            /  * * * * * * \\\n");
    printf("           |  [oo] [oo] [oo] [oo] [oo]  |\n");
    printf("           |  ========================  |\n");
    printf("            \\                          /\n");
    setColor(12);
    printf("             '------------------------'\n");
    printf("                 \\________________/\n\n");
    setColor(7);

    setColor(10);
    printf("  하노이 쌀국수 여정의 대성공 ]\n\n");
    setColor(7);
    printf("  매서운 오토바이 폭주족 무리를 요리조리 피해 길을 건너고,\n");
    printf("  5초라는 극한의 시간 압박 속에서 정확하게 'PhoBo' 메뉴를 주문했으며,\n");
    printf("  뜨거운 국물이 쏟아지지 않도록 완벽하게 좌우 균형을 잡는 데 성공했습니다!\n\n");
    printf("  이로써 모든 험난한 스테이지를 극복하고 하노이 최고의 쌀국수를 쟁취하였습니다.\n");
    printf("  끝까지 몰입감 있게 플레이해 주셔서 진심으로 감사드립니다!\n");

    printf("\n  --------------------------------------------------------------------\n");
    printf("  [ PROJECT CREDIT ]\n");
    printf("  - 개발 및 설계 : 2371214 이지형\n");
    printf("  - 개발 이유: 프로그래밍랩 기말고사 게임개발 프로젝트 진행\n");
    printf("  - 개발 환경 : C Console Application\n");
    printf("  --------------------------------------------------------------------\n");

    printf("\n  >> 아무 키나 누르면 프로그램이 최종 종료됩니다. 감사합니다.");
    _getch();
    return 0;
}