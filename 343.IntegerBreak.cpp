#include "defines.h"

class Solution {
public:
    int integerBreak(int n) {
        int dp[60];
        if (n == 2) {return 1;}
        if (n == 3) {return 2;}
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            int n = 0;
            for (int j = 1; j <= i / 2; j++) {
                n = max(n, dp[j] * dp[i - j]);
            }
            dp[i] = n;
        }
        return dp[n];
    }
};