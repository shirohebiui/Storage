#include <iostream>
#define MaxNode 100
#define INF 1e9
#define min(a,b) (a<b?a:b)
int vsize, esize;
int dist[MaxNode][MaxNode];

void init_dist() {
    for(int u=0; u<vsize; u++) {
        for(int v=0; v<vsize; v++) {
            dist[u][v] = INF;
        }
        dist[u][u] = 0;
    }
}
void floyd() { 
    for(int w=0; w<vsize; w++){
        for(int u=0; u<vsize; u++) {
            for(int v=0; v<vsize; v++) {
                dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> vsize >> esize;
    init_dist();

    int start, end;
    while(esize--) {
        std::cin >> start >> end;
        dist[start-1][end-1] = 1;
        dist[end-1][start-1] = 1;
    }

    floyd();
    return 0;
}