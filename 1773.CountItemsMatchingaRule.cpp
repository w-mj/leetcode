#include "defines.h"


class Solution {
public:

    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        map<string, int> m[3];
        for (int i = 0; i < items.size(); ++i) {
            m[0][items[i][0]] += 1;
            m[1][items[i][1]] += 1;
            m[2][items[i][2]] += 1;
        }
        if (ruleKey == "type") {
            return m[0][ruleValue];
        }
        if (ruleKey == "color") {
            return m[1][ruleValue];
        }
        if (ruleKey == "name") {
            return m[2][ruleValue];
        }
        return -1;
    }
};