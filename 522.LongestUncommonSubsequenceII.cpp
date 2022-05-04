#include "defines.h"


class Solution {
public:
    bool is_sub_str(const string& origin, const string& sub) {
        int i = 0;
        int j = 0;
        while (i < origin.size() && j < sub.size()) {
            if (origin[i] == sub[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == sub.size();
    }

    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2){return s1.size() > s2.size(); });
        for (int i = 0; i < strs.size(); i++) {
            bool good = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (strs[i].size() > strs[j].size()) {
                    break;
                }
                if (is_sub_str(strs[j], strs[i])) {
                    good = false;
                    break;
                }
            }
            if (good) {
                return strs[i].size();
            }
        }
        return -1;
    }
};