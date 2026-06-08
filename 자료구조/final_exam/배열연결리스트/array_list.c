#include <stdio.h>
#include <stdlib.h> //exit()함수 사용을 위해 헤더파일추가
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE]; //배열정의
	int size; //현재 리스트에 저장된 항목들의 개수
}ArrayListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType*L) { //리스트 초기화 함수
	L->size = 0;
}

int is_full(ArrayListType* L) { //리스트가 가득 차 있으면 1을 반환
	return L->size == MAX_LIST_SIZE;
}

int is_empty(ArrayListType* L) { //리스트가 비어있으면 1을 반환
	return L->size == 0;
}

element get_entry(ArrayListType* L,int pos) { //원하는 위치의 값 리턴
	if (pos < 0 || pos >= L->size) //꺼낼수없는 경우의 오류처리
		error("위치오류"); //error함수 사용
	return L->array[pos];
}

void print_list(ArrayListType* L) {
	if (is_empty(L))
		printf("리스트가 비어있습니다\n");
	for (int i = 0; i < L->size; i++) {
		printf("%d-> ", L->array[i]);
	}
	printf("\n");
}

void insert_last(ArrayListType* L,element data) {
	if (L->size >= MAX_LIST_SIZE)
		error("리스트가 가득 찼습니다\n");
	L->array[L->size++] = data;
}

void insert(ArrayListType* L, int pos, element data) { //중간에 삽입함수!!!
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) { //꽉차있지 않고 0<=삽입위치<=L->size이면 삽입가능
		for (int i = L->size; i > pos; i--) {
			L->array[i] = L->array[i - 1];
		}
		L->array[pos] = data;
		L->size++; //리스트크기 1늘리기
	}
}

element delete(ArrayListType* L, int pos) {
	if (is_empty(L) || pos < 0 || pos >= L->size)
		error("삭제범위를 넘어섰습니다");
	element temp = L->array[pos];
	for (int i = pos; i < (L->size-1); i++) {
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return temp;
}


int main() {
	ArrayListType list;
	init(&list);
	insert(&list, 0, 10);   print_list(&list);
	insert(&list, 0, 20);   print_list(&list);
	insert(&list, 0, 30);   print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0);       print_list(&list);

	return 0;
}