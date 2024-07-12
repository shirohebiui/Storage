#include <cstdio>

//READ
constexpr int RSZ = 1<<16;
char rbuf[RSZ], *rbp;
const char *rbp_end = rbuf + RSZ;
inline char ReadChar() {
    if(rbp == rbp_end) fread(rbp = rbuf, sizeof(char), RSZ, stdin);
    return *rbp++;
}
inline int ReadInt() {
    int ret = 0;
    // for (char c = ReadChar(); c&0x10; ret = ret*10 + (c&0x0F), c = ReadChar());
    //EOF가 입력될 가능성이 있는
    for (char c = ReadChar(); c&16; ret = ret*10 + (c&15), c = ReadChar());
    return ret;
}

//WRITE
constexpr int WSZ = 1<<16;
char wbuf[WSZ]; int wbp;
const int wbp_end = WSZ - 30;

inline void wbuf_flush() {
    fwrite(wbuf, 1, wbp, stdout);
    wbp = 0;
}

inline void wbuf_write(char *p) {
    while(*p != '\0') wbuf[wbp++] = *p++;
    if(wbp > wbp_end) wbuf_flush();
}

