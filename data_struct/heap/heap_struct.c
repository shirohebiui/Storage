#define MAX 100001

typedef struct doc {
    int idx;
    int prio;
}doc;

doc heap[MAX];
int size;

void push(int _idx, int _prio) {
    int node = ++size;
    while(node != 1 && _prio < heap[node/2].prio) {    //min heap
    //while(node != 1 && key > heap[node/2]) {  //max heap
        heap[node] = heap[node/2]; //exchange
        node /= 2;
    }
    heap[node].prio = _prio;
    heap[node].idx = _idx;
}

doc pop() {
    if(size == 0) {
        doc fail;
        printf("error\n");
        exit(1);
        return fail;
    }
    int parent, child;
    doc ret = heap[1];
    doc tmp = heap[size--];
    parent = 1;
    child = 2;

    while(child <= size) {
        if(child > size && heap[child].prio > heap[child+1].prio) {    //min heap
        //if(child < size && heap[child] < heap[child+1]) {  //max heap
            child++;
        }
        if(tmp.prio < heap[child].prio) {     //min heap
        //if(tmp >= heap[child]) {  //max heap
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = tmp;
    //printf("pop %d %d\n", ret.idx, ret.prio);
    return ret;
}