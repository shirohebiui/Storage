#include <cstdlib>
void p(int a, int b){
	char *vis = (char *)malloc(b+1);
	int i=0;
	while(a>0) {
		if(i++ == 1) {cout << '.'; break;}
		cout << a/b;
		a = (a%b)*10;
	}
	while(a>0) {
		if(vis[a%b]) break;
		vis[a%b] = 1;
		cout << a/b;
		a = (a%b)*10;
	}
	free(vis);
}