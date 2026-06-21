#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// 색상 변경 함수 (이전 스테이지들과 동기화)
void setStage3Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 윈도우 창 물리 진동 효과 (국물 쏟았을 때 연출용)
void triggerStage3Shake() {
    HWND hwnd = GetForegroundWindow();
    RECT rect;
    if (hwnd != NULL) {
        GetWindowRect(hwnd, &rect);
        int x = rect.left; int y = rect.top;
        int width = rect.right - rect.left; int height = rect.bottom - rect.top;
        for (int i = 0; i < 4; i++) {
            MoveWindow(hwnd, x + 15, y, width, height, TRUE); Sleep(25);
            MoveWindow(hwnd, x - 15, y, width, height, TRUE); Sleep(25);
        }
        MoveWindow(hwnd, x, y, width, height, TRUE);
    }
}

int main() {
    int gauge = 10;       // 게이지 시작 위치 (중앙이 10)
    int max_gauge = 20;   // 게이지 최대 크기
    int walk_count = 0;   // 걸어간 걸음 수
    int target_walk = 30; // 30걸음 도달 시 성공

    srand((unsigned int)time(NULL));

    while (1) {
        system("cls");
        printf("\n");
        printf("  ===============================================================\n");
        printf("  ##        [ STAGE 3 : 뜨거운 국물 들고 자리 잡기 ]          ##\n");
        printf("  ===============================================================\n\n");

        printf("  \"방금 나온 쌀국수가 엄청나게 뜨겁습니다!\"\n");
        printf("  손님들 사이를 지나 빈자리까지 국물이 넘치지 않게 균형을 잡으세요!\n\n");

        // 현재 이동 거리 시각화 바 (이모티콘 제거 후 화살표 처리)
        printf("  ▶ 빈자리까지 남은 거리 : [");
        setStage3Color(14); // 노란색 진행 바
        for (int i = 0; i < target_walk; i++) {
            if (i < walk_count) printf("=");
            else if (i == walk_count) printf(">"); // 🏃 대신 진행 방향 화살표
            else printf(" ");
        }
        setStage3Color(7);
        printf("] (%d / %d 걸음)\n\n", walk_count, target_walk);

        // --- 게이지 바 리모델링 디자인 (텍스트 호환성 100% 버전) ---
        printf("        [!] 왼쪽으로 쏟아짐주의             오른쪽으로 쏟아짐주의 [!]\n");
        printf("        ┌─────────────────────────────────────────────────────┐\n");
        printf("        │ ");

        for (int i = 0; i <= max_gauge; i++) {
            if (i == gauge) {
                setStage3Color(12); printf("O"); setStage3Color(7);  // 🍜 대신 빨간색 알파벳 대문자 O (국물)
            }
            else if (i == 0 || i == max_gauge) {
                setStage3Color(13); printf("X"); setStage3Color(7);  // 💥 대신 자홍색 대문자 X (위험 구역)
            }
            else if (i == 10) {
                setStage3Color(10); printf("|"); setStage3Color(7);  // 특수 기호 대신 깔끔한 파이프라인 | (중앙선)
            }
            else {
                printf(".");
            }
        }

        printf(" │\n");
        printf("        └─────────────────────────────────────────────────────┘\n");
        printf("         [A키] 누르면 왼쪽으로 당김            [D키] 누르면 오른쪽으로 당김\n\n");
        // ------------------------------------------------------------------

        // 1. 탈락 조건 검사하기 (게이지가 양쪽 벽에 닿으면 쏟아짐)
        if (gauge <= 0 || gauge >= max_gauge) {
            setStage3Color(12); // 빨간색 경고
            printf("  [ GAME OVER : 국물 폭발 ]\n");
            printf("  으아악! 균형이 무너지면서 뜨거운 쌀국수 국물을 온몸에 쏟았습니다!\n");
            printf("  지형님은 맛보지도 못하고 화상을 입은 채 식당을 터덜터덜 걸어나옵니다...\n");
            setStage3Color(7);
            Beep(150, 600);
            triggerStage3Shake(); // 화면 물리 진동 연출
            break;
        }

        // 2. 승리 조건 검사
        if (walk_count >= target_walk) {
            setStage3Color(10); // 초록색 성공
            printf("  [ STAGE 3 CLEAR : 완벽한 여정의 끝 ]\n");
            printf("  도달 성공! 안전하게 빈자리에 그릇을 내려놓았습니다.\n");
            printf("  라임즙을 짜넣고 최고의 쌀국수를 들이킵니다. 대성공! \n");
            setStage3Color(7);
            // 최종 승리 축하 나팔 (도레미파솔라시도~!)
            Beep(523, 100); Beep(587, 100); Beep(659, 100); Beep(698, 100);
            Beep(784, 100); Beep(880, 100); Beep(988, 100); Beep(1046, 400);
            break;
        }

        // 3. 무작위로 무게중심 흔들기 ( -1, 0, 1 중 하나 )
        int shake = (rand() % 3) - 1;
        gauge += shake;

        // 4. 입력시 균형 잡기
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') gauge -= 2;
            if (ch == 'd' || ch == 'D') gauge += 2;
            Beep(800, 20); // 조작 시 짧은 틱 사운드로 손맛 추가
        }

        walk_count++; // 한 루프 버텨낼 때마다 한 걸음씩 이동
        Sleep(150);   // 흔들리는 속도 조절
    }

    printf("\n  >> 아무 키나 누르면 프로그램을 종료합니다... ");
    _getch();
    return 0;
}