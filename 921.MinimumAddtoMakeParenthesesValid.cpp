#include "defines.h"


class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cnt = 0;
        for (char c: s) {
            cnt += c == '('? 1 : -1;
            if (cnt < 0) {
                ans += 1;
                cnt = 0;
            }
        }
        ans += cnt;
        return ans;
    }
};