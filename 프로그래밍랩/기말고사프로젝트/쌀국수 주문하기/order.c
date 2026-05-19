#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp 함수 사용을 위한 헤더
#include <time.h>   // clock 함수 사용을 위한 헤더
#include <conio.h>

int main() {
    char quiz[20] = "PhoBo"; // 정답 단어 (소고기 쌀국수)
    char input[20];
    clock_t start_time, end_time;
    double limit_time = 5.0; // 제한 시간을 5초로 설정!

    printf("\n=== [STAGE 2단계(베타버전) : 쌀국수 주문하기] ===\n");
    printf("점원이 말한 베트남어를 5초 안에 똑같이 타이핑하세요!\n");
    printf("=>>제시어: [%s]\n\n", quiz);
    printf("입력 : ");

    start_time = clock(); // 타이머 시작!
    scanf("%s", input);
    end_time = clock();   // 타이머 종료!

    // 걸린 시간 계산
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n걸린 시간: %.2f초\n", duration);

    // 1. 시간 초과 검사
    if (duration > limit_time) {
        printf("시간 초과! 점원이 알아듣지 못하고 쫓겨났습니다. (주문 실패)\n");
    }
    // 2. 정답 일치 검사
    else if (strcmp(quiz, input) == 0) {
        printf("성공! 점원이 고개를 끄덕이며 주방으로 주문을 넣습니다.\n");
    }
    // 3. 오타 검사
    else {
        printf("오타 발생! 잘못된 주문입니다. [%s]가 아닙니다.\n", input);
    }

    _getch();
    return 0;
}
