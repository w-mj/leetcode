#ifdef LOCAL_DEBUG
#include "defines.h"
#endif


vector<string> split(const string& s, char sp) {
    int i = 0, l = 0;
    vector<string> res;
    while (i < s.size()) {
        if (s[i] == sp) {
            if (i != l)
                res.push_back(s.substr(l, i - l));
            l = i + 1;
        }
        i++;
    }
    if (i != l)
        res.push_back(s.substr(l, i - l));
    return res;
}

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        map<string, vector<string>> next;
        vector<string> splited = split(text, ' ');
        for (size_t i = 0; i < splited.size() - 2; i++) {
            if (splited[i] == first && splited[i + 1] == second)
                ans.emplace_back(splited[i + 2]);
        }
        return ans;
    }
};


#ifdef LOCAL_DEBUG
int main(void) {
    Solution s;
    vector<string> ans = s.findOcurrences("we will we will rock you", "wea", "will");
    printList(ans);
    return 0;
}
#endif
