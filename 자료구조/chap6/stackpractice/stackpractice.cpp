#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType*p) {
	p->top = -1;
}

int is_empty(StackType *p) {
	return (p->top == -1);
}

int is_full(StackType* p) {
	return (p->top == MAX_STACK_SIZE - 1);
}

void push(StackType* p, element item) {
	if (is_full(p)) {
		fprintf(stderr,"스택이 꽉차있어 넣을수 없습니다(push함수).");
		exit(1);
	}
	else
		p->data[++(p->top)] = item;
}

element pop(StackType*p) {
	if (is_empty(p)) {
		fprintf(stderr, "스택이 비어있어 삭제할수 없습니다.");
		exit(1);
	}
	else
		return p->data[(p->top)--];
}

element peek(StackType* p) {
	if (is_empty(p)) {
		fprintf(stderr, "스택이 비어있어 삭제할수 없습니다.");
		exit(1);
	}
	else
		return p->data[(p->top)];
}

int main() {
	StackType p;

	init_stack(&p);
	push(&p, 1);
	push(&p, 2);
	push(&p, 3);
	printf("%d\n", pop(&p));
	printf("%d\n", pop(&p));
	printf("%d\n", pop(&p));
	return 0;
}