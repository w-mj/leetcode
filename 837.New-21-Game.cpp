#ifdef LOCAL_DEBUG
#include "defines.h"

#define ull unsigned long long 
class Solution {
public:
    // 每次获得[1, W]中的随机一个数字
    // 当获得数字的总和 >= K时停止
    // 求总和 <= N的概率
    double new21Game(int N, int K, int W) {
        double dp[N + W + 1];
        for (int k = K; k <= N; ++k)
            dp[k] = 1.0;

        double S = min(N - K + 1, W);
        for (int k = K - 1; k >= 0; --k) {
            dp[k] = S / W;
            S += dp[k] - dp[k + W];
        }
        return dp[0];
    }
};


int main(void) {
    Solution s;
    return 0;
}

#endif