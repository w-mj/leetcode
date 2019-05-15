#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        if (n == 0)
            return result;
        for (int i = 0; i < n; i++)
            result.push_back(vector<int>(n, -1));
        int t = 0;
        int cnt = 0;
        while (t <= n / 2) {
            for (int i = t; i < n - t; i++)
                result[t][i] = ++cnt;
            for (int i = t + 1; i < n - t; i++)
                result[i][n - t - 1] = ++cnt;
            for (int i = n - t - 2; i >= t; i--)
                result[n - t - 1][i] = ++cnt;
            for (int i = n - t - 2; i > t; i--)
                result[i][t] = ++cnt;
            t++;
        }
        return result;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> r;
    r = s.generateMatrix(5);
    printList(r);

    return 0;
}

#endif