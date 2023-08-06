#define MAX_SIZE 1000

void merge(int *data, int p, int q, int r) {
	int i = p, j = q+1, k = p;
	int tmp[MAX_SIZE];
	while(i<=q && j<=r) {
		if(data[i] <= data[j]) {
			tmp[k++] = data[i++];
		} else {
			tmp[k++] = data[j++];
		}
	}
	while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
	for(int a = p; a<=r; a++) data[a] = tmp[a];
}

void merge_sort(int *data, int p, int r) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(data, p, q);
		merge_sort(data, q+1, r);
		merge(data, p, q, r);
	}
}