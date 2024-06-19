#define MAX_SIZE 52
char board[MAX_SIZE][MAX_SIZE]; int n, m;
void init_board() {
    board[0][m] = board[n][m] = board[n][0] = board[0][0] = 1;
    for(int i=1; i<n; ++i) {
        board[i][0] = 1;
        board[i][m] = 1;
    }
    for(int i=1; i<m; ++i) {
        board[0][i] = 1;
        board[n][i] = 1;
    }
}