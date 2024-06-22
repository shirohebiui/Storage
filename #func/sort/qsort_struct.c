void swap(void *s1, void *s2, size_t size) {
    void *tmp = (void *)malloc(sizeof(size));
    memmove(tmp, s1, size);
    memmove(s1, s2, size);
    memmove(s2, tmp, size);
    free(tmp);
}

void quick_sort(ch *arr, int start, int end) {
    if(start > end) return;
    int left = start;
    int right = end;
    int pivot = arr[(left + right)/2].frequency;
    while(left <= right) {
        while(arr[left].frequency < pivot) left++;
        while(arr[right].frequency > pivot) right--;
        if(left <= right) swap(&arr[left++], &arr[right--], sizeof(arr[0]));
    }
    quick_sort(arr, start, right);
    quick_sort(arr, left, end);
}