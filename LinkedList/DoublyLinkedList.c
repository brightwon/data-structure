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


// 공백 리스트 생성하기
linkedList* createLinkedList() {
	linkedList* DL;
	DL = (linkedList*)malloc(sizeof(linkedList));
	DL->head = NULL;
	return DL;
}


// 리스트 출력하기
void printList(linkedList* DL) {
	node* p;
	printf("리스트 = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}


// 첫 번째 노드 삽입 연산
void insertNode(linkedList* DL, node* pre, char *x) {
	node *newNode;
	newNode = (node*)malloc(sizeof(node));
	strcpy(newNode->data, x);
	
	if (DL->head == NULL) { // 공백 리스트 일 때
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


// 노드 삭제하기
void deleteNode(linkedList* DL, node* old) {
	if (DL->head == NULL) return; // 공백 리스트 일 때
	else if (old == NULL) return; // 삭제할 노드가 NULL 일 때
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		free(old);
	}
}


// 노드 찾기
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
	insertNode(DL, NULL, "월");

	p = searchNode(DL, "월");
	insertNode(DL, p, "수");

	p = searchNode(DL, "수");
	insertNode(DL, p, "금");
	printList(DL);

	deleteNode(DL, p);
	printList(DL);
	return 0;
}