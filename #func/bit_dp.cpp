
#define MaxV 16 //MAX VSIZE
#define INF 0x7F7F7F7F
int vsize, cost[MaxV][MaxV], dp[MaxV][1<<MaxV];

int all_vis; // = 1<<vsize-1
int TSP(int now, int mask) {
    if(dp[now][mask]) return dp[now][mask];
    if(mask == all_vis) {
        if(cost[now][0]) return cost[now][0];
        else return INF;
    }
    int ret = INF;
    FOR(i, 0, vsize) {
        if(cost[now][i] && !(mask&(1<<i))) {
            ret = min(ret, TSP(i, mask|(1<<i)) + cost[now][i]);
        }
    }
    return dp[now][mask] = ret;
}