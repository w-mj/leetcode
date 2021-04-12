/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[2][n];
        for (int i = 0; i < m; i++)
            dp[i%2][n - 1] = 1;
        for (int i = 0; i < n; i++){
            dp[(m - 1)%2][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i % 2][j] = dp[(i + 1)%2][j] + dp[i % 2][j + 1];
            }
        }
        return dp[0][0];
    }
};

