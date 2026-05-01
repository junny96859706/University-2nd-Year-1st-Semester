#include <stdio.h>
//하노이탑 알고리즘-중간고사로 출제확률높다!!!(반드시 이해할것)

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) {
        printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
    }
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d을 %c에서 %c로 옮긴다.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }

}

int main() {
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}