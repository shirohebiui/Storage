#include <stdio.h>
#include <string.h>
#define MAX 100
#define INF 999
int node = 5;
// a b c d e

int w[MAX][MAX] = {
	{0  ,2  ,INF,4  ,5  },
	{2  ,0  ,2  ,2  ,INF},
	{INF,2  ,0  ,4  ,1  },
	{4  ,2  ,4  ,0  ,INF},
	{5  ,INF,1  ,INF,0  }
};
int dp[MAX][MAX];

void print(int map[][MAX]) {
	for(int i=0; i<node; i++) {
		for(int j=0; j<node ; j++) {
            if(map[i][j] >= INF) printf(" INF");
			else printf(" %3d", map[i][j]);
		}
		printf("\n");
	}
}

void Floyd() { //Floyd-Warshall O(N^3)
	for(int k=0; k<node; k++) {
		for(int i=0; i<node; i++) {
			for(int j=0; j<node; j++) {
				if(dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
}

int main() {
    printf("가중치 그래프\n");
    print(w);
	memmove(dp, w, MAX*node*sizeof(int));
    printf("최적해 그래프\n");
	Floyd();
    print(dp);
	return 0;
}