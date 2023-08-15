int rear = 0;
int stack[10] = {0, };
void push(int k) {
    stack[rear++] = k;
}

int pop() {
    if(rear >= 0) {
        return stack[rear--];
    }
    return 0;
}