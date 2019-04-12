#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data[4];
	struct Node* link;
} node;

typedef struct {
	node* head;
} linkedList;

// 공백 리스트 생성
linkedList* createLinkedList(void) {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	return L;
}

// 링크드 리스트 모든 메모리 해제
void freeLinkedList(linkedList* L) {
	node* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// 링크드 리스트 내용 출력
void printList(linkedList* L) {
	node* p;
	printf("리스트 = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertFirst(linkedList* L, char* x) {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddle(linkedList* L, node* pre, char* x) {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, x);

	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLast(linkedList* L, char* x) {
	node* newNode;
	node* temp;
	newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

void deleteNode(linkedList* L, node* p) {
	node* pre;
	if (L->head == NULL) return;
	if (L->head->link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else {
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

node* searchNode(linkedList* L, char* x) {
	node* temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

int main() {
	linkedList* L;
	node* p;
	L = createLinkedList();

	insertLast(L, "월");
	insertLast(L, "화");
	insertLast(L, "금");
	printList(L);

	p = searchNode(L, "화");
	insertMiddle(L, p, "수");
	printList(L);

	p = searchNode(L, "금");
	deleteNode(L, p);
	printList(L);

	freeLinkedList(L);
	return 0;
}