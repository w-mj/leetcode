#include "defines.h"

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxn = 1;
        for (int i = n - 1;i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] - arr[i] == difference) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxn = max(maxn, dp[i]);
                }
            }
        }
        return maxn;
    }
};