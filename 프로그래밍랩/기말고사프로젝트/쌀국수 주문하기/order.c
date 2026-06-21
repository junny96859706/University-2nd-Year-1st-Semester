#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h> // strcmp 함수 사용을 위한 헤더
#include <time.h>   // clock 함수 사용을 위한 헤더
#include <conio.h>

// 색상 변경 함수 (Stage 1과 동일)
void setStage2Color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 윈도우 창 물리 진동 효과 (실패 시 연출용)
void triggerStage2Shake() {
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
    char quiz[20] = "PhoBo"; // 정답 단어 (소고기 쌀국수)
    char input[20];
    clock_t start_time, end_time;
    double limit_time = 5.0; // 제한 시간 5초

    system("cls");
    printf("\n");
    printf("  ===============================================================\n");
    printf("  ##        [ STAGE 2 : 하노이 명품 쌀국수 주문하기 ]          ##\n");
    printf("  ===============================================================\n\n");

    // 1. 점원 및 쌀국수 그릇 아스키아트 디자인
    setStage2Color(14); // 노란색 점원
    printf("         (皿- )  <  \"어서 오십시오, 손님!\n");
    printf("          /||\\       5초 안에 정확히 주문하셔야 조리가 시작됩니다!\"\n");
    setStage2Color(7);
    printf("          /  \\ \n");
    printf("       ============\n");
    printf("       |  ");
    setStage2Color(13); printf("  ??? ");
    setStage2Color(7); printf("  |\n");
    printf("        \\________/   [ 최고의 소고기 쌀국수 대기 중 ]\n\n");

    printf("  ┌─────────────────────────────────────────────────────────────┐\n");
    printf("  │  🗣️  점원의 제시어  : ");
    setStage2Color(13); printf("[%s]", quiz); setStage2Color(7);
    printf(" (대소문자 정확히!)         │\n");
    printf("  └─────────────────────────────────────────────────────────────┘\n\n");

    printf("  >> 단어를 똑같이 타이핑 후 Enter를 누르세요!\n");
    printf("  ▶ 주문 입력 : ");

    // 2. 타이머 가동 및 입력
    start_time = clock();
    scanf("%s", input);
    end_time = clock();

    // 걸린 시간 계산
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n  ===============================================================\n");
    printf("  ⏱️  주문 소요 시간: ");
    setStage2Color(11); printf("%.2f초", total_time); setStage2Color(7);
    printf(" (제한시간: 5.00초)\n");
    printf("  ===============================================================\n\n");

    // 3. 결과 분기 및 시각적/청각적 이펙트 처리
    // [분기 1] 시간 초과
    if (total_time > limit_time) {
        setStage2Color(12); // 빨간색 경고
        printf("  💥 [주문 실패 : TIME OVER]\n");
        printf("  시간이 너무 오래 걸렸습니다! 점원이 알아듣지 못하고 문을 닫았습니다.\n");
        setStage2Color(7);
        Beep(150, 500);
        triggerStage2Shake(); // 화면 흔들기 효과
    }
    // [분기 2] 정답 성공
    else if (strcmp(quiz, input) == 0) {
        setStage2Color(10); // 초록색 성공
        printf("  🎉 [주문 대성공 : SUCCESS]\n");
        printf("  완벽한 발음입니다! 점원이 고개를 끄덕이며 주방으로 주문을 넣습니다.\n");
        printf("  따끈따끈한 국물을 마시며 하노이 여정을 성공적으로 마무리합니다!\n");
        setStage2Color(7);
        Beep(523, 100); Beep(659, 100); Beep(784, 100); Beep(1046, 300); // 승리 나팔 소리
    }
    // [분기 3] 오타 발생
    else {
        setStage2Color(12); // 빨간색 경고
        printf("  [주문 실패 : TYPO ERROR]\n");
        printf("  지형님이 입력한 주문: [%s]\n", input);
        printf("  하노이에는 그런 메뉴가 없습니다! 잘못된 주문으로 쫓겨났습니다.\n");
        setStage2Color(7);
        Beep(300, 200); Beep(300, 200); //경고음
        triggerStage2Shake(); // 화면 흔들기 효과
    }

    printf("\n  >> 아무 키나 누르면 게임이 최종 종료됩니다... ");
    _getch();
    return 0;
}