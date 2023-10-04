#define MAX 100

void print_all_1D(int *arr, int size) {
    // sizeof(arr) ok
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_all_2D(int (*arr)[MAX], int row, int col) {
    for(int i = 0; i < row; i++) {
        printf("depth %d : ", i);
        for(int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}