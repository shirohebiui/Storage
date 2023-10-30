#define MAX 100
int data[MAX][MAX];

// 붙어있는 숫자열
void input_data(int size) {
    char key[MAX];
    for(int i=0; i<size; i++) {
        scanf("%s", key);
        for(int j=0; j<size; j++) {
            data[i][j] = key[j] - '0';
        }
    }
}

// 띄어있는 숫자열
void input_data(int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf(" %d", &data[i][j]);
        }
    }
}