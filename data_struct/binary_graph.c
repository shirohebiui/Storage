graph[vsize][vsize/8];

graph[u][v/8] += 1<<(v%8);
graph[v][u/8] += 1<<(u%8);

void test() {
    for(int i=1; i<=vsize; i++) {
        for(int j=1; j<=vsize; j++) {
            if(graph[i][j/8] & 1<<(j%8))
                printf("1");
            else printf("0");
        }
        printf("\n");
    }
}