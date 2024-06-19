void init(int n) {
    for(int i=1; i<=vsize; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    a < b ? parent[a] = b : parent[b] = a;
}