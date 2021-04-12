#ifdef LOCAL_DEBUG
#include "defines.h"
class MagicDictionary {
public:
    vector<string> d;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        d = dict;
    }

    int differences(const string& w1, const string& w2) {
        int dif_cnt = 0;
        for (size_t i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                dif_cnt ++;
                if (dif_cnt == 2)
                    return 2;
            }
        }
        return dif_cnt;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(const string& word) {
        for (const string& s: d) {
            if (s.size() == word.size()) {
                if (differences(s, word) == 1)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
int main(void) {
    MagicDictionary s;
    return 0;
}

#endif