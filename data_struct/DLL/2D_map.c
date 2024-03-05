#include <stdio.h>
#define MAX 2500
typedef pt char

typedef struct pos{
    pt y, x;
    struct pos *next, *prev;
}pos;

pos *head, *tail;
pos nodes[MAX]; int size;

void init_dlist() {
    head = (pos*)malloc(sizeof(pos));
	tail = (pos*)malloc(sizeof(pos));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void insert_node(pt y, pt x) {
    pos *p = &nodes[size++];
    p->y = y; p->x = x;
    p->prev = tail->prev;
    p->next = tail;
    tail->prev->next = p;
    tail->prev = p;
}

void delete_node(pos *d) {
    d->prev->next = d->next;
    d->next->prev = d->prev;
}

int main() {
    return 0;
}