#include "defines.h"
#include <cctype>

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        ans.reserve(queries.size());

        for (string& qu: queries) {
            int i = 0, j = 0;
            while (i < qu.size() && j < pattern.size()) {
                if (qu[i] == pattern[j]) {
                    i++;
                    j++;
                } else if (qu[i] >= 'a' && qu[i] <= 'z') {
                    i++;
                } else {
                    break;
                }
            }
            if (j != pattern.size() ) {
                ans.push_back(false);
            } else {
                while (i < qu.size() && islower(qu[i])) {
                    i++;
                }
                ans.push_back(i == qu.size());
            }
        }

        return ans;
    }
};