#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;

// 공백인지 아닌지 확인
int isEmpty() {
	if(top == NULL) return 1;
	else return 0;
}

// 스택에 노드 삽입
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;

	temp->link = top;
	top = temp;
}

// 스택 top 노드 삭제
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n스택이 비어있습니다.");
		return 0;
	}
	else {
		item = top->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

// 스택 top의 원소 검색
element peek() {
	if (top == NULL) {
		printf("\n스택이 비어있습니다.");
		return 0;
	}
	else {
		return top->data;
	}
}

// 스택 출력하기
void printStack() {
	stackNode* p = top;
	printf("\n 스택 = [ ");
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