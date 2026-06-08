#include <stdio.h>
#include <stdlib.h> //exit()함수 사용을 위해서 해더 선언

typedef int element;

typedef struct {
	struct ListNode* link;
	element data;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //노드 동적할당
	p->data = value;

	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) { //노드 pre뒤에 새로운 노드 삽입
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	p->link = pre->link;
	pre->link = p;

	return head; //리턴하기 위해 head사용(의미x)
}

ListNode* delete_first(ListNode* head) { //리스트의 첫노드 삭제
	ListNode* temp = head;
	if (head == NULL)
		return NULL;
	head = head->link;
	free(temp);

	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) { //pre가 가리키는 다음 노드를 삭제한다.
	ListNode* temp;
	temp = pre->link;
	pre->link = temp->link;

	free(temp);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d-> ", p->data);
	}
	printf("NULL \n");
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* search_list(ListNode* head, element value) {
	ListNode* p = head;

	while (p != NULL) {
		if (p->data == value)
			return p;
		p = p->link;
	}
	return NULL; //탐색실패
}

ListNode* concat_list(ListNode* head1, ListNode* head2) { //두개의 연결리스트를 합치는 concat함수
	if (head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	else {
		ListNode* p = head1;
		while (p->link != NULL) 
			p = p->link;

		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (q != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main() {
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}