#include <stdio.h>
#include <string.h>

char tree[134217729];int N;
void prefix(int node);
void infix(int node);
void postfix(int node);

int main() {
    scanf("%d", &N);
    char parent, left, right;
    tree[1] = 'A';
    for(int i=0; i<N; i++) {
        scanf(" %c %c %c", &parent, &left, &right);
        for(int i=1; i<26; i++) {
            if(tree[i] == parent) {
                if(left != '.') tree[i*2] = left;
                if(right != '.') tree[i*2+1] = right;
                break;
            }
        }
    }
    prefix(1); printf("\n");
    infix(1); printf("\n");
    postfix(1); printf("\n");
    return 0;
}

void prefix(int node) {
    if(tree[node] == 0) return;
    printf("%c", tree[node]);
    prefix(node*2);
    prefix(node*2+1);
}

void infix(int node) {
    if(tree[node] == 0) return;
    infix(node*2);
    printf("%c", tree[node]);
    infix(node*2+1);
}


void postfix(int node) {
    if(tree[node] == 0) return;
    postfix(node*2);
    postfix(node*2+1);
    printf("%c", tree[node]);
}