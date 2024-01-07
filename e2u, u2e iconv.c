#include <string.h>
#include <iconv.h>

int main() {
    char output[100];
    char input[100];
    iconv_t it = iconv_open("UTF-8//TRANSLIT//IGNORE", "CP949//TRANSLIT//IGNORE"); //e2u
    // iconv_t it = iconv_open("CP949//TRANSLIT//IGNORE", "UTF-8//TRANSLIT//IGNORE"); //u2e
    while (1) {
        scanf("%[^\n]s", input); getchar();
        size_t srclen = strlen(input);
        size_t dstlen = srclen * 3; //e2u
        // size_t dstlen = srclen ; //u2e
        char *src = input;
        char *dst = output;
        iconv(it, &src, &srclen, &dst, &dstlen);
    }
    iconv_close(it);
    return 0;
}