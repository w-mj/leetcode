#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K)
    {
        int N = A.size();
        double P[N + 1];
        for (int i = 0; i < N; ++i)
            P[i + 1] = P[i] + A[i];

        double dp[N];;
        for (int i = 0; i < N; ++i)
            dp[i] = (P[N] - P[i]) / (N - i);

        for (int k = 0; k < K - 1; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = i + 1; j < N; ++j)
                    dp[i] = max(dp[i], (P[j] - P[i]) / (j - i) + dp[j]);

        return dp[0];
    }
};

int main(void)
{
    Solution s;
    vector<int> v = { 9, 1, 2, 3, 9 };
    cout << s.largestSumOfAverages(v, 3) << endl;
    vector<int> v2 = { 4, 1, 7, 5, 6, 2, 3 };
    cout << s.largestSumOfAverages(v2, 4) << " " << "18.16667" << endl;
    return 0;
}

#endif
