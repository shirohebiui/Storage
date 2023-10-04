#include <stdio.h>
#define MAX 100001

int rear=0;
int stack[MAX];

void push(int data) {
	stack[rear++] = data;
}

int pop() {
	if(rear > 0) {
        return stack[--rear];
	} else {
        return -1;
	}
}

int IsEmpty() {
	if(rear > 0) {
        return 0;
	} else {
        return 1;
	}
}