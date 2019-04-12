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

// ���� ����Ʈ ����
linkedList* createLinkedList(void) {
	linkedList* L;
	L = (linkedList*)malloc(sizeof(linkedList));
	L->head = NULL;
	return L;
}

// ��ũ�� ����Ʈ ��� �޸� ����
void freeLinkedList(linkedList* L) {
	node* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

// ��ũ�� ����Ʈ ���� ���
void printList(linkedList* L) {
	node* p;
	printf("����Ʈ = (");
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

	insertLast(L, "��");
	insertLast(L, "ȭ");
	insertLast(L, "��");
	printList(L);

	p = searchNode(L, "ȭ");
	insertMiddle(L, p, "��");
	printList(L);

	p = searchNode(L, "��");
	deleteNode(L, p);
	printList(L);

	freeLinkedList(L);
	return 0;
}