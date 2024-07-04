vector<string> name;	// insert 할 이름들

struct Trie {	// Trie 구조체
    map<string, Trie*> next;	// vecotr로 만들어도 되지만 중복 안되는 map으로 생성 (시간단축!)
    
    // insert
    void insert(vector<string>& strVector, int strSize, int index) {
        if (strSize <= index) {
            return;
        }
        
        map<string, Trie*>::iterator iter = next.find(strVector[index]);
        
        // 다음 철자와 맞는 글자가 없다면 새로 next Trie 생성
        if (iter == next.end()) {
            Trie* newNext = new Trie;
            next.insert({strVector[index], newNext});
            newNext->insert(strVector, strSize, index + 1);
        }
        // 다음 철자와 맞는 글자가 있다면 다음 글자로 이동후 insert
        else {
            iter->second->insert(strVector, strSize, index + 1);
        }
    }
    
    // print(search) 여기선 완벽한 search는 아니고 모두 출력
    void print(int level) {
        for (auto& food : next) {
            for (int i=0; i<level; i++) {
                cout << "--";
            }
            cout << food.first << "\n";
            food.second->print(level + 1);
        }
    }
};