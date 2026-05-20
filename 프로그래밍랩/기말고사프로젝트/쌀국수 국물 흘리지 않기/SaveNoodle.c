#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int main() {
    int gauge = 10;       // 게이지 시작 위치 (중앙이 10)
    int max_gauge = 20;   // 게이지 최대 크기
    int walk_count = 0;   // 걸어간 걸음 수
    int target_walk = 30; // 30걸음을 무사히 걸어가면 성공으로 표시

    srand((unsigned int)time(NULL));

    while (1) {
        system("cls");
        printf("\n=== [STAGE 3 : 뜨거운 국물 들고 자리 잡기] ===\n");
        printf(" 쌀국수가 넘치지 않게 A와 D를 눌러 균형을 잡으세요!\n");
        printf(" 목표 자리까지 거리: %d / %d 걸음\n\n", walk_count, target_walk);

        // --- 게이지 바 시각적으로 그리기 ---
        printf("\n===================================\n");
        printf("|쏟아짐주의 [");
        for (int i = 0; i <= max_gauge; i++) {
            if (i == gauge) printf("|"); // 현재 무게중심 그리기!!!!
            else printf(" ");
        }
        printf("]|\n");
        printf("===================================\n\n\n");
        // ----------------------------------

        // 1. 탈락 조건 검사하기 (게이지가 양쪽 벽에 닿으면 쏟아짐)
        if (gauge <= 0 || gauge >= max_gauge) {
            printf("국물을 쏟았습니다! 흔들리던 쌀국수가 엎어졌습니다. (게임오버)\n");
            break;
        }

        // 2. 승리 조건 검사
        if (walk_count >= target_walk) {
            printf("🎉 도달 성공! 무사히 빈자리에 앉아 따뜻한 쌀국수를 먹습니다. 완벽한 여행입니다!\n");
            break;
        }

        // 3. 무작위로 무게중심 흔들기 ( -1, 0, 1 중 하나로 흔들리게 하기)
        int shake = (rand() % 3) - 1;
        gauge += shake;

        // 4.입력시 균형 잡기
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'a' || ch == 'A') gauge -= 2; // 왼쪽으로 당기기
            if (ch == 'd' || ch == 'D') gauge += 2; // 오른쪽으로 당기기
        }

        walk_count++; // 한 루프 버텨낼 때마다 한 걸음씩 이동
        Sleep(150);   // 흔들리는 속도 조절
    }

    _getch();
    return 0;
}