#include <stdio.h>
#define MAX 100001

int top=0;
int stack[MAX];

void push(int data) {
	stack[top++] = data;
}

int pop() {
	if(top > 0) {
        return stack[--top];
	} else {
        return -1;
	}
}

int IsEmpty() {
	if(top > 0) {
        return 0;
	} else {
        return 1;
	}
}