
#include <cstdio>
#include <cstdlib>
#include <cstring>
char *itoa(int input, char *output, int radix) {
    if(input == 0) {*output = '0'; *(output+1) = '\0'; return output;} //0일경우 예외처리

    char *tmp = (char *)malloc(sizeof(strlen(output)+1));
    *tmp++ = '\0';
    if(input < 0) {input ^= 1<<31; *tmp++ = '-';} //음수처리

    //itoa func
    while(input) {
        *tmp++ = '0' + input%radix;
        input /= radix;
    }
    tmp--;
    char *p = output; //output pointer
    while(*tmp != '\0') {
        *p++ = *tmp--;
    }
    *p = '\0';
    free(tmp);
    return output;
}