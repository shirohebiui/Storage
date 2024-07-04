
#define FOR(val, start, end) for(int val=(start); val<(end); ++val)

#include <vector>
#include <cstring>
struct Trie{
    bool end;
    Trie *next[26];
    //생성자
    Trie() : end(false) {
        memset(next, 0x00, sizeof(next));
    }
    //소멸자
    ~Trie() {
        FOR(i, 0, 26) {
            if(next[i]) delete next[i];
        }
    }

    //트라이에 문자열 삽입
    void insert(const char *key) {
        if(*key == '\0') end = true; //문자열 종료 여부
        else {
            int curr = *key - 'A';
            if(next[curr] == NULL) next[curr] = new Trie(); //탐색이 처음되는 지점일 경우 동적할당
            next[curr]->insert(key+1); //다음 문자 삽입
        }
    }
    void loopinsert(const char *key) {
        Trie *now = this;
        while(*key != '\0') {
            int cur = *key - '0';
            if(now->next[cur] == NULL) now->next[cur] = new Trie();
            now = now->next[cur];
            key++;
        }
        now->end = 1;
    }
    //트라이에서 문자열 찾기
    Trie *find(const char *key) {
        if(*key == '\0') return this; //문자열 끝나는 위치 반환
        int curr = *key - 'A';
        if(next[curr] == NULL) return NULL;
        return next[curr]->find(key+1);
    }
    bool loopfind(const char *key) {
        Trie *now = this;
        while(*key != '\0') {
            int cur = *key - '0';
            if(now->end == true) return false;
            if(now->next[cur] != NULL) now = now->next[cur];
            else return true;
            key++;
        }
        return true;
    }
};