#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc사용을 위한 헤더

typedef int element;
typedef struct DListNode { //이중연결리스트 노드
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* before, element data){ //새노드를 before노드 뒤에 삽입하는 함수
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;

	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return; //head노드는 삭제할수 없음
	
	// A <-> (removed) <-> B
	removed->llink->rlink = removed->rlink; //A->B
	removed->rlink->llink = removed->llink; //A<-B
	free(removed); //removed노드 메모리 해제
}

DListNode* search(DListNode* head, element data) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		if (p->data == data) { //데이터를 찾았으면
			return p;
		}
		else if (p == head->llink) { //데이터를 못찾았으면
			return NULL;
		}
	}
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, 1); // head <-> 1
	dinsert(head, 2); // head <-> 2 <-> 1
	dinsert(head, 3); // head <-> 3 <-> 2 <-> 1
	print_dlist(head);

	element data;

	while (1) {
		printf("탐색할 값: ");
		scanf("%d", &data);

		if (search(head, data) != NULL) {
			printf("값이 리스트 안에 있습니다.\n");
		}
		else {
			printf("값이 리스트 안에 없습니다.\n");
		}
	}

	return 0;

}