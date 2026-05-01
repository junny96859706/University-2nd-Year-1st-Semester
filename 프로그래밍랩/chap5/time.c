#include <stdio.h>
#define _CRT_SECURE_NO_WARINGS
//오류나는 부분 해결하기!!!!!!!

struct TIME {
	int seconds;
	int minutes;
	int hours;
};

//t1:시작시간, t2:종료시간, differ:두시간의 차이
void diff_time(struct TIME t1, struct TIME t2, struct TIME* differ) {
	
	if (t2.seconds - t1.seconds < 0) {
		differ->seconds = 60 + t2.seconds - t1.seconds;
		--t2.minutes;
	}
	else
	differ->seconds = t2.seconds - t1.seconds;

	if (t2.minutes - t1.minutes < 0) {
		differ->minutes = 60 + t2.minutes - t1.minutes;
		--t2.hours;
	}
	else
	differ->minutes = t2.minutes - t1.minutes;

	if (t2.hours - t1.hours < 0) {
		differ->hours = 24+t2.hours - t1.hours;
	}
	else
	differ->hours = t2.hours - t1.hours;
}

int main() {
	struct TIME t1;
	struct TIME t2;
	struct TIME differ;

	printf("시작시간을 입력하세요:");
	scanf("%d%d%d",&t1.hours,&t1.minutes,&t1.seconds);
	printf("\n");

	printf("종료시간을 입력하세요:");
	scanf("%d%d%d", &t2.hours, &t2.minutes, &t2.seconds);
	printf("\n");

	diff_time(t1, t2, &differ);
	printf("총 걸린시간은: %d시간 %d분 %d초 입니다", differ.hours, differ.minutes, differ.seconds);


}

