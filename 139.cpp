#include "defines.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool f[s.size() + 1];
        memset(f, 0, s.size() + 1);
        f[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                    f[i] = true;
            }
        }
        return f[s.size()];
    }
};

int main(void) {
    Solution s;
    vector<string> v = {"apple", "pen"};
    cout << s.wordBreak("applepenapple", v);
    return 0;
}