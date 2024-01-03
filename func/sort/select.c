#include <stdio.h>
#define MAX 10

int arr[MAX] = {7,2,3,9,28,11};

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int i, j, idx;
    for(i=0; i<MAX-1; i++) {
        idx = i;
        for(j=i+1; j<MAX ;j++) {
            if(arr[idx] > arr[j]) {
                idx = j;
            }
        }
        if(idx != i)
            swap(&arr[i], &arr[idx]);
    }

    for(i=0; i<MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}