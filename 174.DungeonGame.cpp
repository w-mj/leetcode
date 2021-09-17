#include "defines.h"

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &d)
    {
        int n = d.size();
        int m = d[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = n - 1; i >= 0 ; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = min(d[i][j], 0);
                } else if (i == n - 1) {
                    dp[i][j] = min(dp[i][j + 1] + d[i][j], 0);
                } else if (j == m - 1) {
                    dp[i][j] = min(dp[i + 1][j] + d[i][j], 0);
                } else {
                    dp[i][j] = min(max(dp[i + 1][j], dp[i][j + 1]) + d[i][j], 0);
                }
            }
        }

        return 1 - dp[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v;
    v = getVectorOfVectorOfInt("[[-2,-3,3],[-5,-10,100],[10,30,-5]]", NULL);
    cout << s.calculateMinimumHP(v) << endl;
    v = getVectorOfVectorOfInt("[[1,-3,3],[0,-2,0],[-3,-3,-3]]", NULL);
    cout << s.calculateMinimumHP(v) << endl;
    v = getVectorOfVectorOfInt("[[0]]", NULL);
    cout << s.calculateMinimumHP(v) << endl;
}