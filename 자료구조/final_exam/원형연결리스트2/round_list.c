#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	struct ListNode* link;
	element data;
}ListNode;

void print_list(ListNode* head) { //head부터 출력하면 안되고, head->link부터 출력해야 한다!!!!!
	ListNode* p;
	if (head == NULL)
		return;
	
	p = head->link;
	do {
		printf("%d-> ", p->data);
		p = p->link;
	} while (p != head->link); 
	//출발점과 도착점이 완벽하게 같은 노드이기 때문에 
	//while문으로 작성시 시작조건과 종료조건이 똑같아서 조건문에서 팅겨나가버린다
}

ListNode* insert_first(ListNode* head, element value) { //원형연결리스트 처음에 삽입
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head; //변경된 헤드 포인터 반환
}

ListNode* insert_last(ListNode *head,element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		
		p->link = head->link;
		head->link = p;
		head = p;
	}

	return head; //변경된 헤드 포인터를 반환한다.
}

void free_list(ListNode* head) { //전체노드 연결헤제함수
	if (head == NULL)
		return;
	ListNode* p = head->link;
	ListNode* temp;

	while (p != head) {
		temp = p;
		p = p->link;
		free(temp);
	}
	free(head);
}

int main() {
	ListNode* head = NULL;
	//list: 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 40);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}