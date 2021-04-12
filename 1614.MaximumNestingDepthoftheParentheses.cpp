#include "defines.h"

class Solution {
public:
    int maxDepth(string s) {
        int maxd = 0;
        int d = 0;
        for (auto c: s) {
            if (c == '(') {
                d++;
            } else if (c == ')') {
                d--;
            } else {
                continue;
            }
            maxd = max(maxd, d);
        }
        return maxd;
    }
};