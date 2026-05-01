#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct { // 큐 타입
	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// ===== 기존원형큐 코드 시작 ======

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
void init_queue(DequeType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//후단삽입함수
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("덱 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//전단삭제함수
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("덱이 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//전단삽입함수
void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("덱 포화상태입니다");
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	q->data[q->front] = val;
}

//후단삭제함수
element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("덱이 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

//======================================================

int main(void) {
	DequeType q;
	init_queue(&q);

	char input[MAX_QUEUE_SIZE];
	int palindrome = 1;

	printf("문자열을 입력하세요:");
	scanf("%s", input);
	
	int len = strlen(input);
	for (int i = 0; i < len; i++) {
		char ch = input[i];
		if (isalpha(ch)) {
			add_rear(&q, tolower(ch));
		}
	}


	while(!is_empty(&q)) {
		char firstchar = delete_front(&q);
		if (is_empty(&q))
			break;
		char lastchar = delete_rear(&q);
		if (firstchar != lastchar) {
			palindrome = 0;
			break;
		}

	}

	if (palindrome == 1)
		printf("입력결과 회문입니다!!!!!");
	else
		printf("입력결과 회문이 아닙니다.");
	return 0;
}