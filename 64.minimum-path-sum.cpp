/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#ifdef LOCAL_DEBUG
#include "defines.h"
#endif

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; j++)
            grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

// int main(void)
// {
//     vector<vector<int>> in = {
//         { 1, 3, 1 },
//         { 1, 5, 1 },
//         { 4, 2, 1 }
//     };
//     Solution s;
//     cout << s.minPathSum(in) << endl;
//     return 0;
// }
