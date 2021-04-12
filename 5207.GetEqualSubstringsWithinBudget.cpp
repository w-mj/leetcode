#include "defines.h"

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost(s.size(), 0);
        for (size_t i = 0; i < s.size(); i++) {
            cost[i] = abs(s[i] - t[i]);
        }
        int ss = 0;
        int se = 0;
        int ssum = 0;
        int max_len = -1;
        for (auto i: cost) {
            ssum += i;
            se += 1;
            while (ssum > maxCost) {
                ssum -= cost[ss];
                ss += 1;
            }
            max_len = max(max_len, se - ss);
        }
        return max_len;
    }
};