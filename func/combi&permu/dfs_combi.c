#define MAX 1000
int count;
int select[MAX], data[MAX];
int n, k;

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
    if(cnt == k) {
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