#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* llink;
	char data[4];
	struct Node* rlink;
} node;

typedef struct {
	node* head;
} linkedList;


// ���� ����Ʈ �����ϱ�
linkedList* createLinkedList() {
	linkedList* DL;
	DL = (linkedList*)malloc(sizeof(linkedList));
	DL->head = NULL;
	return DL;
}


// ����Ʈ ����ϱ�
void printList(linkedList* DL) {
	node* p;
	printf("����Ʈ = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}


// ù ��° ��� ���� ����
void insertNode(linkedList* DL, node* pre, char *x) {
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, x);
	
	if (DL->head == NULL) { // ���� ����Ʈ �� ��
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DL->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != NULL)
			newNode->rlink->llink = newNode;
	}
}


// ��� �����ϱ�
void deleteNode(linkedList* DL, node* old) {
	if (DL->head == NULL) return; // ���� ����Ʈ �� ��
	else if (old == NULL) return; // ������ ��尡 NULL �� ��
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
	}
}


// ��� ã��
node* searchNode(linkedList* DL, char* x) {
	node* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->rlink;
	}
	return temp;
}

int main() {
	linkedList* DL;
	node* p;

	DL = createLinkedList();
	insertNode(DL, NULL, "��");

	p = searchNode(DL, "��");
	insertNode(DL, p, "��");

	p = searchNode(DL, "��");
	insertNode(DL, p, "��");
	printList(DL);

	deleteNode(DL, p);
	printList(DL);
	return 0;
}