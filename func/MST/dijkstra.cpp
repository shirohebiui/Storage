#include <iostream>
#define MaxNode 1000
#define INF 1e9
#define min(a,b) (a<b?a:b)

int graph[MaxNode][MaxNode];
int dist[MaxNode];
char vis[MaxNode];
int vsize, esize, start, end;

int getMinV() {
    int minV = 0;
    int minW = INF;
    for(int i=0; i<vsize; i++) {
        if(dist[i] < minW && !vis[i]) {
            minW = dist[i];
            minV = i;
        }
    }
    return minV;
}

void dijkstra() {
    vis[start] = 1;
    
    int u, w;
    for(int i=0; i<vsize; i++) {
        u = getMinV();
        vis[u] = 1;
        for(int w=0; w<vsize; w++) {
            if(!vis[w]) dist[w] = min(dist[w], dist[u] + graph[u][w]);
        }
    }
}

void init_input() {
    std::cin >> vsize >> esize;
    for(int i=0; i<vsize; i++)
        for(int j=0; j<vsize; j++)
            graph[i][j] = INF;
    
    int w;
    while(esize--) {
        std::cin >> start >> end >> w;
        graph[start-1][end-1] = min(graph[start-1][end-1], w);
    }
    std::cin >> start >> end;
    start--; end--;

    for(int i=0; i<vsize; i++) {
        dist[i] = graph[start][i];
    }
    dist[start] = 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    init_input();
    dijkstra();
    std::cout << dist[end] << "\n";
    return 0;
}