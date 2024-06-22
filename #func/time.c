#include <stdio.h>
#include <string.h>
#include <time.h>
#define MB 1048576


clock_t t;
void set_time() {t = clock();}
float check_time() {return clock() - t;}

int half = MB/2;

int main() {
    unsigned char DATA[4][MB];
    //전체 초기화
    set_time();
    for(int loop=0; loop<1000; loop++) {
        for(int i=0; i<4; i++)
            for(int j=0; j<MB; j++)
                DATA[i][j] = 0xFF;
        for(int i=0; i<4; i++)
            for(int j=0; j<MB; j++)
                DATA[i][j] = 0x00;
    }
    printf("4MB for문을 통해 전체 초기화 : %.1f ms\n", check_time());

    set_time();
    for(int loop=0; loop<10000; loop++) {
        memset(DATA, 0xFF, 4*MB);
        memset(DATA, 0x00, 4*MB);
    }
    printf("4MB memset을 통해 전체 초기화 : %.1f ms\n", check_time());
    
    set_time();
    for(int loop=0; loop<10000; loop++) {
        for(int i=0; i<4; i++)
            memset(&DATA[i], 0xFF, MB/2);
        for(int i=0; i<4; i++)
            memset(&DATA[i][MB/2], 0xFF, MB/2);
        
        for(int i=0; i<4; i++)
            memset(&DATA[i], 0x00, MB/2);
        for(int i=0; i<4; i++)
            memset(&DATA[i][MB/2], 0x00, MB/2);
    }
    printf("4MB memset을 통해 전체 초기화 : %.1f ms\n", check_time());

    //부분 초기화
    set_time();
    for(int loop=0; loop<1000; loop++) {
        for(int i=0; i<4; i++)
            for(int j=half; j<MB; j++)
                DATA[i][j] = 0xFF;
        for(int i=0; i<4; i++)
            for(int j=half; j<MB; j++)
                DATA[i][j] = 0x00;
    }
    printf("4MB for문을 통해 절반 초기화 : %.1f ms\n", check_time());

    set_time();
    for(int loop=0; loop<10000; loop++) {
        for(int i=0; i<4; i++)
            memset(&DATA[i][half], 0xFF, half);
        for(int i=0; i<4; i++)
            memset(&DATA[i][half], 0x00, half);
    }
    printf("4MB memset을 통해 절반 초기화 : %.1f ms\n", check_time());
}