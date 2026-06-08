#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	struct ListNode* link;
	element data;
}ListNode;

void print_list(ListNode* head) { //head부터 출력하면 안되고, head->link부터 출력해야 한다!!!!!
	ListNode* p;
	if (p == NULL)
		return;
	
	p = head->link;
	do {
		printf("%d-> ", p->data);
		p = p->link;
	} while (p != head->link);
}