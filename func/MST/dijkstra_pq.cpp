#include <iostream>
#include <queue>
#include <vector>
#define MaxNode 20000
#define INF 1e9
using namespace std;
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

struct edge{
    int vertex, weight;
    
    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

vector<edge> graph[MaxNode];
int dist[MaxNode];
int vsize, esize, start;

void dijkstra(int start) {
    priority_queue<edge> pq;

    pq.push({start, 0});
    dist[start] = 0;
    while(!pq.empty()) {
        int min_dist = pq.top().weight;
        int now = pq.top().vertex;
        pq.pop();
        if(dist[now] < min_dist) continue;
        // for(auto& edge : graph[now]) {
        //     int cost = min_dist + edge.weight;
        //     if(cost < dist[edge.vertex]) {
        //         dist[edge.vertex] = cost;
        //         pq.push({edge.vertex, cost}); 
        //     }
        // }
        FOR(i, 0, graph[now].size()) {
            int cost = min_dist + graph[now][i].weight;
            if(cost < dist[graph[now][i].vertex]) {
                dist[graph[now][i].vertex] = cost;
                pq.push({graph[now][i].vertex, cost});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> vsize >> esize >> start; start--;
    while(esize--) {
        int v, u, weight;
        cin >> v >> u >> weight;
        graph[v-1].push_back({u-1, weight});
    }

    fill(dist, dist+vsize, INF);
    dijkstra(start);
    FOR(i, 0, vsize) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}