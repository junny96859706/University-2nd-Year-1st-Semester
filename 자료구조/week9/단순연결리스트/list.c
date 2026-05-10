#define _CRT_SECURE_NO_WARNINGS //10주차수업 - 단순연결리스트
#include <stdio.h>   
#include <stdlib.h>
//시험범위는 연결리스트의 응용(다항식)까지는 나오지 않고 reverse까지만 나온다!!!

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat_list(ListNode* head1, ListNode* head2) { //두개의 연결리스트를 합치는 함수
	if (head1 == NULL)return head1;
	else if (head2 == NULL)return head2;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
	}
	return head1;
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;
	//p는 역순으로 만들리스트/q는 현재 역순으로 만들 노드,r은 이미 역순으로 변경된 리스트

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;

}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	int number = 0;
	printf("숫자를 입력하세요: ");
	scanf("%d", &number);

	if (search_list(head, number) != NULL)
		printf("리스트에서 %d를 찾았습니다. \n", number);
	else
		printf("리스트에서 %d를 찾지 못했습니다.\n", number);

	printf("\n");
	printf("리스트에서 두개를 합치는 코드\n");

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);

	ListNode* total = concat_list(head1, head2);
	print_list(total);

	printf("\n");
	printf("리스트를 역순으로 만드는 코드\n");

	ListNode* head3 = NULL;
	ListNode* head4 = NULL;

	head3 = insert_first(head3, 10);
	head3 = insert_first(head3, 20);
	head3 = insert_first(head3, 30);
	print_list(head3);

	head4 = reverse(head3);
	print_list(head4);
	return 0;
}