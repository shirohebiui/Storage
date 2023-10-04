#include <stdbool.h>
// n C m
int arr[20];
bool visited[20];
int N, M;

void depth(int c,int t) {
	if (c == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
        return;
	}

	for (int i = t; i < N; i++) {
		if (!visited[i]) {
			arr[c] = i+1;
			visited[i] = true;
			depth(c + 1,i);
			visited[i] = false;
		}
	}
}

// n C m 에서 m이 작을 경우
void combine_N(int rear, int one, int two, int thr) {
    if(one != -1 && two != -1 && thr != -1) {
        //여기에서 조합의 경우 도출
    } 
    for(int i=0; i<rear; i++) {
        if(one == -1) {
            combine_N(rear, i, two, thr);
        } else if(i != one) {
            if(two == -1) {
                combine_N(rear, one, i, thr);
            } else if(i != two) {
                if(thr == -1) {
                    combine_N(rear, one, two, i);
                }
            }
        }
    }
}