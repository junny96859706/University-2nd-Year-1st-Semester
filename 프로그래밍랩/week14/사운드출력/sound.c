#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")

#define MusicFile "wave_file.wav" //같은 폴더에 파일이 있을때

int main(void) {
	PlaySound(
		TEXT(MusicFile),
		NULL,
		SND_FILENAME | SND_ASYNC | SND_LOOP //반복재생
	);

	while (1) {
		int a;

		printf("종료하려면 0을 입력하세요: ");
		scanf("%d", &a);

		if (a == 0) {
			PlaySound(NULL, 0, 0); //재생중지

			Sleep(1000); //1초대기(음악이 완전히 멈출때까지	)

			printf("음악이 종료되었습니다");
			return 0;
		}
	}
}