#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
#define max_vsize 1001
#define min(a,b) (a<b?a:b)

typedef struct G{
    int adj;
    int dist;
    struct G *link;
}G;

G graph[max_vsize];
int vsize, esize;
int start, end;
char visited[max_vsize];
int dist[max_vsize];

void init_graph(int vsize) {
    for(int i=0; i<vsize; i++) {
        graph[i].link = NULL;
    }
}

void insert(int u, int w, int dist) {
    G *v = &graph[u];
    while(v->link) {
        v = v->link;
        if(v->adj == w) {
            v->dist = min(v->dist, dist);
            return;
        }
    }
    G *new = (G *)malloc(sizeof(G));
    v->link = new;
    new->adj = w;
    new->dist = dist;
    new->link = NULL;
}

int GetMinVertex(int node) {
    int min_v = 0;
    int min_w = INF;
    for(int i=0; i<vsize; i++) {
        if(dist[i] < min_w && !visited[i]) {
            min_w = dist[i];
            min_v = i;
        }
    }
    return min_v;
}

int dist_adj(int start, int end) {
    G *s = &graph[start];
    while(s->link) {
        s = s->link;
        if(s->adj == end) return s->dist;
    }
    return INF;
}


void dijkstra() {
    //init dist
    for(int i=0; i<vsize; i++) dist[i] = INF;
    G *s = &graph[start];
    while(s->link) {
        s = s->link;
        dist[s->adj] = s->dist;
    }

    visited[start] = 1;

    int u, w;
    for(int i=0; i<vsize; i++) {
        u = GetMinVertex(start);
        visited[u] = 1;
        for(w=0; w<vsize; w++) {
            if(!visited[w])
                dist[w] = min(dist[w], dist[u] + dist_adj(u, w));
        }
    }
}

int main() {
    scanf(" %d %d", &vsize, &esize);
    init_graph(vsize);
    int u, w, weight;
    while(esize--) {
        scanf(" %d %d %d", &u, &w, &weight);
        u--; w--;
        insert(u, w, weight);
    }
    scanf(" %d %d", &start, &end);
    start--; end--;
    dijkstra();
    printf("%d\n", dist[end]);
    return 0;
}