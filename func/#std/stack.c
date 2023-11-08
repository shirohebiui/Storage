#include <stdlib.h>
#include <stdio.h>
typedef long element;        // 교체!
#define MAX_STACK_SIZE 1000
 
 
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;
 
// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}
 
// 공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
    //printf("push %d : %c\n", s->top, s->data[s->top]);
}
// 삭제함수
element pop(StackType *s)
{
    //printf("pop %d : %c\n", s->top, s->data[s->top]);
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러pop\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러peek\n");
        exit(1);
    }
    else return s->data[s->top];
}