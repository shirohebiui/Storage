#include <stdio.h>
#define MAX 100000

int rear = 0, front = 0;
int queue[MAX];

void push(int data) {
    queue[rear++ % MAX] = data;
}

int pop() {
    if(front < rear) {
        return queue[front++];
    } else {
        return -1;
    }
}

int IsValid() {
    return rear - front;
}

int empty() {
    if(IsValid() > 0) {
        return 0;
    } {
        return 1;
    }
}