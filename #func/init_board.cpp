#define MAX_SIZE 1002
int board[MAX_SIZE][MAX_SIZE]; int n, m;
void init_board() {
    board[0][m] = board[n][m] = board[n][0] = board[0][0] = 1;
    for(int i=1; i<n; ++i) board[i][0] = board[i][m] = 1;
    for(int i=1; i<m; ++i) board[0][i] = board[n][i] = 1;
}