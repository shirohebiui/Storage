#include <stdio.h>
#define MAX 100001

long heap[MAX];
int size;

void push(int key) {
    int node = ++size;
    while(node != 1 && key < heap[node/2]) {    //min heap
    //while(node != 1 && key > heap[node/2]) {  //max heap
        heap[node] = heap[node/2]; //exchange
        node /= 2;
    }
    heap[node] = key;
}

long pop() {
    if(size == 0)
        return 0;
    int parent, child;
    long ret = heap[1];
    long tmp = heap[size--];
    parent = 1;
    child = 2;

    while(child <= size) {
        if(child < size && heap[child] > heap[child+1]) {    //min heap
        //if(child < size && heap[child] < heap[child+1]) {  //max heap
            child++;
        }
        if(tmp < heap[child]) {     //min heap
        //if(tmp >= heap[child]) {  //max heap
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    return ret;
}