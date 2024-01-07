#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(const char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 4
#define SIZE 10

void radix_sort(int list[], int n) {
    QueueType queues[BUCKETS];
    int factor = 1;
    for(int i=0; i<BUCKETS; i++) {
        init_queue(&queues[i]);
    }

    for(int d=0; d<DIGITS; d++) {
        //factor없으면 1의 자리만 확인하기때문에 factor로 버킷에 넣을 자릿수를 올려줘야함
        for(int i=0; i<n; i++)
            enqueue(&queues[(list[i]/ factor)%10], list[i]);
        
        int i=0;
        for(int b=0; b<BUCKETS; b++) {
            while(!is_empty(&queues[b])) 
                list[i++] = dequeue(&queues[b]);
        }
        factor *= 10;
    }
}

void print_list(int list[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[SIZE];
    srand(time(NULL));

    for(int i=0; i<SIZE; i++) {
        list[i] = rand() % 10000;
    }

    printf("Origin\n");
    print_list(list, SIZE);

    radix_sort(list, SIZE);

    printf("Sorting\n");
    print_list(list, SIZE);


    return 0;
}