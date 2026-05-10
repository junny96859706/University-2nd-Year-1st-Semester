#define _CRT_SECURE_NO_WARNINGS //10주차수업 - 단순연결리스트
#include <stdio.h>   
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

bool is_empty(ListNode *head) {
	if (head == NULL)
		return true;
	else
		return false;
}

bool is_full(ListNode* head) {
	return false;
}

int get_length(ListNode* head) {
	int num = 0;
	ListNode* p = head;
	while (p != NULL) {
		num++;
		p = p->link;
	}
	return num;
}

bool is_in_list(ListNode* head, element item) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == item) return true;
		p = p->link;
	}
	return false;
}

void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL N\n");
}

ListNode* clear(ListNode* head) {
	ListNode* p = head;
	ListNode* next;
	while (p != NULL) {
		next = p->link;
		free(p);
		p = next;
	}
	head = NULL;
	return head;
}

ListNode* delete(ListNode* head, element item) {
	ListNode* p = head;
	ListNode* pre = NULL;
	while (p != NULL) {
		if (p->data == item) {
			if (pre == NULL) {
				head = p->link;
				free(p);
				return head;
			}
			else {
				pre->link = p->link;
				free(p);
				return head;
			}
		}
		pre = p;
		p = p->link;
	}
	return head;
}

ListNode* add(ListNode* head, element item) {
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = item;
	
	ListNode* curr = head; //현재
	ListNode* pre = NULL; //이전

	while (curr != NULL && curr->data < item) {
		pre = curr;
		curr = curr->link;
	}
	if (pre == NULL) { //맨앞에 삽입해야하는경우
		new->link = head;
		head = new;
	}
	else { //중간이나 끝에 삽입하는 경우
		new->link = curr;
		pre->link = new;
	}

	return head;
}

int main() {

}