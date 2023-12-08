typedef long type;
void swap(type *a, type *b) {
    type tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(type *data, type start, type end) {
	if(start >= end) return;
	type left = start;
	type right = end;
    type pivot = data[ (left + right) / 2 ];
	while(left<=right) {
		while(data[left] < pivot) left++;
		while(data[right] > pivot) right--;
		if(left<=right) {
			swap(&data[left], &data[right]);
			left++; right--;
		}
	}
	quick_sort(data, start, right);
	quick_sort(data, left, end);
}