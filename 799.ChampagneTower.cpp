#include "defines.h"

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[128][128] = {0};       
        dp[0][0] = poured;
        int r = 1;
        for (r = 1; r <= 100; r++) {
            bool all_zero = true;
            for (int g = 0; g < r + 1; g++) {
                if (g != 0) {
                    dp[r][g] += max(dp[r - 1][g - 1] - 1, 0.0) / 2;
                }
                dp[r][g] += max(dp[r - 1][g] - 1, 0.0) / 2;
                if (dp[r][g] > 0) {
                    all_zero = false;
                }
                if (r == query_row && g == query_glass) {
                    all_zero = true;
                    break;
                }
            }
            if (all_zero) {
                break;
            }
        }
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        return min(dp[query_row][query_glass], 1.0);
    }
};

int main() {
    Solution s;
    cout << s.champagneTower(0, 0, 0) << endl;
}