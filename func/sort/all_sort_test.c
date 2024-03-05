#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>
#include <time.h>
#define TESTCASE 799
typedef struct word
{
    char eng[50];
    char kor[100];
} word;

word origin[800];
word sort[800];


void init();
void restore();
word *tmp;
iconv_t it;

void input();
int mode;

void sort_menu();

void swap(word *s1, word *s2) {
    *tmp = *s1; *s1 = *s2; *s2 = *tmp;
}

//insert
void insert_sort(word *arr) { //1D arr구현, doubly linked list구현시 swap을 덜 호출해서 시간적으로 좀더 효율적
    int i, j;
    for(i=0; i<TESTCASE; i++) {
        for(j=i; j>0; j--) {
            if(strcmp(arr[j].eng, arr[j-1].eng) < 0)
                swap(&arr[j], &arr[j-1]);
        }
    }
}

//selection
void selection_sort(word *arr) {
    int i, j, idx;
    for(i=0; i<TESTCASE-1; i++) {
        idx = i;
        for(j=i+1; j<TESTCASE ;j++) {
            if(strcmp(arr[j].eng, arr[j-1].eng) < 0)
                idx = j;
        }
        if(idx != i)
            swap(&arr[i], &arr[idx]);
    }
}

//bublle
void bubble_sort(word *arr) {
    int i, j;
    for(i=0; i<TESTCASE; i++) {
        for(j=0; j<TESTCASE-i; j++) {
            if(strcmp(arr[j].eng, arr[j-1].eng) < 0)
                swap(&arr[j], &arr[j-1]);
        }
    }
}

//merge
word tmp_arr[TESTCASE];
void merge(word *data, int left, int mid, int right) {
    int i = left, j = mid+1;
    int now = left;
    while(i <= mid && j <= right) {
        if(strcmp(data[i].eng, data[j].eng) < 0) {
            tmp_arr[now] = data[i++];
        } else {
            tmp_arr[now] = data[j++];
        }
        now++;
    }
    while(i<=mid) tmp_arr[now++] = data[i++];
    while(j<=right) tmp_arr[now++] = data[j++];
    memmove(&data[left], &tmp_arr[left], sizeof(word)*(right - left + 1));
}

void merge_sort(word *data, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}

//quick
char pivot[50];
void quick_sort(word *arr, int start, int end) {
    if(start > end) return;
    int left = start;
    int right = end;
    strcpy(pivot, arr[(left + right)/2].eng);
    while(left <= right) {
        while(strcmp(arr[left].eng, pivot) < 0) left++;
        while(strcmp(arr[right].eng, pivot) > 0) right--;
        if(left <= right) swap(&arr[left++], &arr[right--]);
    }
    quick_sort(arr, start, right);
    quick_sort(arr, left, end);
}

void test() {
    for(int i=0; i<TESTCASE; i++) {
        printf("%s %s\n", sort[i].eng, sort[i].kor);
    }
}

//********************************************************************************************
int main(int argc, char** argv) {
    init(argc, argv);
    // input();
    for(mode = 1; mode<=5; mode++)
        sort_menu();
    // test();
    restore();
    return 0;
}
//********************************************************************************************

void init(int argc, char** argv) {
    it = iconv_open("UTF-8//TRANSLIT//IGNORE", "CP949//TRANSLIT//IGNORE");
    tmp = (word *)malloc(sizeof(word));

    FILE *fp;
	if (argc != 2) {
		fprintf(stderr, "사용법: %s 파일이름\n", argv[0]); exit(1);
	} else if((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "파일 열기 오류\n"); exit(2);
	}
    int size = 0;
    char input[100];
    while (fgets(input, sizeof(input), fp) != NULL) {
        char *token = strtok(input, ",");
        strcpy(origin[size].eng, token);
        token = strtok(NULL, ",");
        token[strcspn(token, "\n")] = '\0';
        size_t srclen = strlen(token);
        size_t dstlen = srclen * 3;
        char *src = token;
        char *dst = origin[size].kor;
        strcpy(origin[size].kor, token);
        iconv(it, &src, &srclen, &dst, &dstlen);
        size++;
    }
    fclose(fp);
}

void input() {
    printf("1.insert_sort\n2.selection_sort\n3.bubble_sort\n4.merge_sort\n5.quick_sort\n");
    scanf("%d", &mode);
}

void restore() {
    free(tmp);
    iconv_close(it);
}

void sort_menu() {
    clock_t t = clock();
    double delay = 0;
    int loop = 1000;
    switch (mode) {
    case 1:
        printf("insert_sort ");
        while(loop--) {
            memmove(sort, origin, sizeof(sort));
            t = clock();
            insert_sort(sort);
            delay += (double)clock() - t;
        }
        break;
    case 2:
        printf("selection_sort ");
        while(loop--) {
            memmove(sort, origin, sizeof(sort));
            t = clock();
            selection_sort(sort);
            delay += (double)clock() - t;
        }
        break;
    case 3:
        printf("bubble_sort ");
        while(loop--) {
            memmove(sort, origin, sizeof(sort));
            t = clock();
            bubble_sort(sort);
            delay += (double)clock() - t;
        }
        break;
    case 4:
        printf("merge_sort ");
        while(loop--) {
            memmove(sort, origin, sizeof(sort));
            t = clock();
            merge_sort(sort, 0, TESTCASE-1);
            delay += (double)clock() - t;
        }
        break;
    case 5:
        printf("quick_sort ");
        while(loop--) {
            memmove(sort, origin, sizeof(sort));
            t = clock();
            quick_sort(sort, 0, TESTCASE-1);
            delay += (double)clock() - t;
        }
        break;
    default:
        break;
    }
    printf("delay time : %.0lf ms\n", delay);
}