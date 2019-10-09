#include "defines.h"


class Solution {
public:
    int min_del(const string& s) {
        vector<vector<int>> dp(s.size() + 1, vector(s.size() + 1, 0));
        for (int span = 1; span < s.size(); span++) {
            for (int i = 0; i + span < s.size(); i++) {
                int j = i + span;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[0][s.size() - 1];
    }
    bool isValidPalindrome(string s, int k) {
        return min_del(s) <= k;
    }
};