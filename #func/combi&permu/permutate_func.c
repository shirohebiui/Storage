#include <stdbool.h>

//중복허용 O
int dep[20];
int n;

void rec(int x) {
	if (x == n) {
		for (int i = 0; i < n; i++) 
			printf("%d ", dep[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		dep[x] = i + 1;
		rec(x + 1);
	}
}

//중복허용 X
int dep[20];
char visited[20];
int n;

void rec(int x) {
	if (x == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", dep[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i + 1]) {
			dep[x] = i + 1;
			visited[i + 1] = true;
			rec(x + 1);
			visited[i + 1] = false;
		}
	}
}