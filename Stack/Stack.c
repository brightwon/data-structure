#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;

element stack[STACK_SIZE];
int top = -1;

// �������� �ƴ��� üũ
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// ������ ���� �� �������� Ȯ��
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	return 0;
}

// ���ÿ� ���� ����
void push(element item) {
	if (isFull()) {
		printf("\n������ ���� á���ϴ�.");
		return;
	}
	else {
		stack[++top] = item;
	}
}

// ���� ���� ����
element pop() {
	if (isEmpty()) {
		printf("\n������ ����ֽ��ϴ�.");
		return 0;
	}
	else {
		return stack[top--];
	}
}

// ���� ���� top ���� Ž��
element peek() {
	if (isEmpty()) {
		printf("\n������ ����ֽ��ϴ�.");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void printStack() {
	int i;
	printf("\n ���� : [ ");
	for (i = 0; i <= top; i++) {
		printf("%d", stack[i]);
	}
	printf(" ]");
}

void main(void) {
	element item;
	printStack();
	push(1); printStack();
	push(2); printStack();
	push(3); printStack();
	
	item = peek();
	printf("peek => %d", item);
	
	item = pop(); printStack();
	printf("pop => %d", item);

	item = pop(); printStack();
	printf("pop => %d", item);

	item = pop(); printStack();
	printf("pop => %d", item);
}