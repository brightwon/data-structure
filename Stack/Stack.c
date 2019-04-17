#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;

element stack[STACK_SIZE];
int top = -1;

// 공백인지 아닌지 체크
int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

// 스택이 가득 찬 상태인지 확인
int isFull() {
	if (top == STACK_SIZE - 1) return 1;
	return 0;
}

// 스택에 원소 삽입
void push(element item) {
	if (isFull()) {
		printf("\n스택이 가득 찼습니다.");
		return;
	}
	else {
		stack[++top] = item;
	}
}

// 스택 원소 제거
element pop() {
	if (isEmpty()) {
		printf("\n스택이 비어있습니다.");
		return 0;
	}
	else {
		return stack[top--];
	}
}

// 현재 스택 top 원소 탐색
element peek() {
	if (isEmpty()) {
		printf("\n스택이 비어있습니다.");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void printStack() {
	int i;
	printf("\n 스택 : [ ");
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