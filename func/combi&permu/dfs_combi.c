#define MAX 1000
int count;
int select[MAX], data[MAX]; //= {1,2,3,4};
int n, r; //nCr n=4 , c=2;

void print() {
    for(int i=0; i<n; i++) {
        if(select[i]) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}

//nCr
void dfs(int idx, int cnt) {
    if(cnt == r) {
        count++; //case count
        print(); //case print
        return;
    }
    for(int i=idx; i<n; i++) {
        if(select[i] == 0) {
            select[i] = 1;
            dfs(i, cnt+1);
            select[i] = 0;
        }
    }
}

//dfs(0,0) 으로실행