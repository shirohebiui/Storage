#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode *left, *right;
}TreeNode;

typedef struct {
    TreeNode *ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

char huffman[26][100];

HeapType * create();
void init(HeapType *h);

TreeNode *make_tree(TreeNode *left, TreeNode *right);
void destroy_tree(TreeNode *root);
int is_leaf(TreeNode *root);

void print_array(int codes[], int n);
void print_codes(TreeNode *root, int codes[], int top);
int output_code(int cnt);
//heap
void insert_min_heap(HeapType *h, element item) {
    int i = ++(h->heap_size);

    while(i != 1 && item.key < h->heap[i/2].key) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1; child = 2;

    while (child <= h->heap_size) {
        if(child < h->heap_size && h->heap[child].key > h->heap[child+1].key)
            child++;
        if(temp.key < h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void huffman_tree(int freq[], char ch_list[], int n) {
    int i;
    TreeNode *node, *x;
    HeapType *heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);
    for(i=0; i<n; i++) {
        node = make_tree(NULL, NULL);
        e.ch = node->ch = ch_list[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insert_min_heap(heap, e);
    }

    for(i=1; i<n; i++) {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);

        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d\n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }

    e = delete_min_heap(heap);
    print_codes(e.ptree, codes, top);
    destroy_tree(e.ptree);

    free(heap);
}

int main() {
    char ch_list[] = "abcdefgh";
    int freq[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int size = strlen(ch_list);
    huffman_tree(freq, ch_list, size);

    //압축률 구하기
    int code_len = output_code(size); //huffman len
    int origin_len = 0;
    for(int i=0; i<size; i++) origin_len += freq[i]; //all ch cnt
    origin_len *= 7; //trans ascii len
    printf("compressibility : %.2lf%%\n", (double)code_len/origin_len * 100);

    return 0;
}

HeapType * create() {
    return (HeapType *)malloc(sizeof(HeapType));
}
void init(HeapType *h) {
    h->heap_size = 0;
}

TreeNode *make_tree(TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = left; node->right = right;
    return node;
}
void destroy_tree(TreeNode *root) {
    if(root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}
int is_leaf(TreeNode *root) {
    return !(root->left) && !(root->right);
}


//test code
void print_array(int codes[], int n) {
    for(int i=0; i<n; i++) printf("%d", codes[i]);
    printf("\n");
}

void print_codes(TreeNode *root, int codes[], int top) {
    if(root->left) {
        codes[top] = 1;
        print_codes(root->left, codes, top+1);
    }
    if(root->right) {
        codes[top] = 0;
        print_codes(root->right, codes, top+1);
    }
    if(is_leaf(root)) {
        printf("%c: ", root->ch);
        print_array(codes, top);
        int i;
        for(i=0; i<top; i++) {
            huffman[root->ch - 'a'][i] = codes[i];
        }
        huffman[root->ch - 'a'][i] = -1;
    }
}

int output_code(int cnt) {
    printf("code : ");
    int code_cnt = 0;
    for(int i=0; i<cnt; i++) {
        char *ptr = huffman[i];
        while(*ptr != -1) {
            printf("%d", *ptr++);
            code_cnt++;
        }
    }
    printf("\n");
    return code_cnt;
}