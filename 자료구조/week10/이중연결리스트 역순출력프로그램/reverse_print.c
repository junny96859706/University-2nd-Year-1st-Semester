#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { //이중연결리스트 노드
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* phead) { //초기화함수
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) { //노드삭제함수
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_dlist(DListNode* phead) { //이중연결리스트 출력 함수
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |->",p->data);
	}
	printf("\n");
}

void print_reverse(DListNode* phead) { //이중연결리스트를 역순으로 출력하는 출력함수
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf(" %d ", p->data);
	}
	printf("\n");
}



int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	int totalNum;
	printf("데이터의 개수를 입력하시오: ");
	scanf("%d", &totalNum);
	for (int i = 0; i < totalNum; i++) {
		element num;
		printf("노드 #%d의 데이터를 입력하시오:", i+1);
		scanf("%d",&num);
		dinsert(head->llink, num);
	}
	
	printf("데이터를 역순으로 출력:");
	print_reverse(head);

	for (int i = 0; i < totalNum; i++) {
		ddelete(head, head->rlink);
	}

	free(head);
}