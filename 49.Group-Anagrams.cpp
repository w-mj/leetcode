#include "defines.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > m;
        for (size_t i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            // if (m.find(t) == m.end());
            //     m.emplace(t, vector<string>());
            m[t].emplace_back(strs[i]);
        }
        vector<vector<string>> result;
        for (const auto& item: m) {
            result.emplace_back(item.second);
        }
        return result;
    }
};

int main(void) {
    Solution s;
    vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> out = s.groupAnagrams(in);
    printList(out);
    return 0;
}

