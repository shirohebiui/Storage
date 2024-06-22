bool flag;
bool vis[9];
void dfs(int idx, int cnt) {
    if(flag) return;
    if(cnt == "check") {
        if("escape_conditon") flag = 1;
    }
    FOR(i, idx, 9) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i+1, cnt+1);
            vis[i] = 0;
        }
    }
}