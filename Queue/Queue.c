#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;
typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;


// 공백 큐 생성
QueueType *createQueue() {
	QueueType *Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

int isEmpty(QueueType *Q) {
	if (Q->front == Q->rear) {
		printf("큐가 비었습니다.");
		return 1;
	}
	else return 0;
}

int isFull(QueueType *Q) {
	if (Q->rear == Q_SIZE - 1) {
		printf("큐가 가득 찼습니다.");
		return 1;
	}
	else return 0;
}

// 큐 rear에 원소 삽입
void enQueue(QueueType *Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// 큐 front 원소 제거
element deQueue(QueueType *Q) {
	if (isEmpty(Q)) return;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// 큐 front 검색
element peek(QueueType *Q) {
	if (isEmpty(Q)) exit(1);
	else return Q->queue[Q->front + 1];
}

void printQ(QueueType *Q) {
	int i;
	printf(" 큐 : [");
	for (i = Q->front + 1; i <= Q->rear; i++) {
		printf("%3c", Q->queue[i]);
	}
	printf(" ]");
}


void main(void) {
	QueueType *Q1 = createQueue();
	element data;
	printf("\n 삽입 A>>"); enQueue(Q1, 'A'); printQ(Q1);
	printf("\n 삽입 B>>"); enQueue(Q1, 'B'); printQ(Q1);
	printf("\n 삽입 C>>"); enQueue(Q1, 'C'); printQ(Q1);

	data = peek(Q1); printf(" peek >> %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(Q1); printQ(Q1);
	printf("\t 삭제 데이터 : %c", data);

	printf("\n 삽입 D>>"); enQueue(Q1, 'D'); printQ(Q1);
	printf("\n 삽입 E>>"); enQueue(Q1, 'E'); printQ(Q1);
}
