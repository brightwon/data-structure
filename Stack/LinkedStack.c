#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

// �������� �ƴ��� Ȯ��
int isEmpty() {
	if(top == NULL) return 1;
	else return 0;
}

// ���ÿ� ��� ����
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;

	temp->link = top;
	top = temp;
}

// ���� top ��� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n������ ����ֽ��ϴ�.");
		return 0;
	}
	else {
		item = top->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

// ���� top�� ���� �˻�
element peek() {
	if (top == NULL) {
		printf("\n������ ����ֽ��ϴ�.");
		return 0;
	}
	else {
		return top->data;
	}
}

// ���� ����ϱ�
void printStack() {
	stackNode* p = top;
	printf("\n ���� = [ ");
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void main(void) {
	element item;
	top = NULL;
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);

	item = pop(); printStack();
	printf("\t pop => %d", item);
}