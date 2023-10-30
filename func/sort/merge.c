#define MAX_SIZE 1000
int data[MAX_SIZE] = {0, }; //input

void merge(int *data, int left, int mid, int right) {
    int tmp[MAX_SIZE] = {0, };
    int i = left, j = mid+1;
    int now = left;
    while(i <= mid && j <= right) {
        if(data[i] < data[j]) {
            tmp[now] = data[i++];
        } else {
            tmp[now] = data[j++];
        }
        now++;
    }
    while(i<=mid) {
        tmp[now++] = data[i++];
    }
    while(j<=right) {
        tmp[now++] = data[j++];
    }
    
    // for(int s = left; s<=right; s++) {
    //     data[s] = tmp[s];
    // }
    memcpy(&data[left], &tmp[left], sizeof(int)*(right - left + 1));
}

void merge_sort(int *data, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}