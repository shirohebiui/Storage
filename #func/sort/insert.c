#include <stdio.h>

int arr[1000];
int MAX;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_sort() {
    int i = 0, j;
    for(i=1; i<MAX; i++) {
        for(j=i; j>0; j--) {
            //printf("%d %d %d\n", i, j, j-1);
            if(arr[j]<arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
        }
    }
}

void print_all() {
    for(int i=0; i<MAX; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void input_data() {
    int i=0;
    while(i < MAX) {
        scanf("%d", &arr[i++]);
    }
}
int main() {
    scanf("%d", &MAX);

    input_data();
    insert_sort();
    print_all();
    return 0;
}