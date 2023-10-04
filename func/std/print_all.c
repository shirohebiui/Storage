#define MAX 100

void print_all_1D(int *arr, int width) {
    for(int w = 0; w < width; w++) {
        printf("%d ", arr[w]);
    }
    printf("\n");
}

void print_all_2D(int (*arr)[MAX], int depth, int width) {
    for(int d = 0; d < depth; d++) {
        printf("depth %d : ", d);
        for(int w = 0; w < width; w++) {
            printf("%d ", arr[d][w]);
        }
        printf("\n");
    }
}