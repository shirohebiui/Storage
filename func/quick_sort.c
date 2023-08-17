void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *data, int start, int end) {
	int left = start;
	int right = end;
    int pivot = data[ (left + right) / 2 ];
	while(left<=right) {
		while(data[left] < pivot) {
			left++;
		}
		while(data[right] > pivot) {
			right--;
		}
		if(left<=right) {
			swap(&data[left], &data[right]);
			left++;
			right--;
		}
	}

	if(start < right)
		quick_sort(start, right);
	if(end > left)
		quick_sort(left, end);
}