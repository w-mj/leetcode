#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;
        int m = matrix.size();
        if (m == 0)
            return result;
        int n = matrix[0].size();
        int TM = 0, TN = 0;
        int cnt = 0;
        int all = m * n;
        while (TM <= m / 2 || TN <= n / 2) {
            for (int i = TN; i <= n - TN - 1 && cnt < all; i++) {
                result.emplace_back(matrix[TM][i]);
                cnt++;
            }
            for (int i = TM + 1; i <= m - TM - 1 && cnt < all; i++) {
                result.emplace_back(matrix[i][n - TN - 1]);
                cnt++;
            }
            for (int i = n - TN - 2; i >= TN && cnt < all; i--) {
                result.emplace_back(matrix[m - TM - 1][i]);
                cnt++;
            }
            for (int i = m - TM - 2; i > TM && cnt < all; i--) {
                result.emplace_back(matrix[i][TN]);
                cnt++;
            }
            if (TM <= (m) / 2)
                TM++;
            if (TN <= (n) / 2)
                TN++;
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> m1 = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 } };
    vector<vector<int>> m2 = {{1}};
    vector<vector<int>> m3 = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };
    vector<vector<int>> m4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto result = s.spiralOrder(m1);
    printList(result);
    result = s.spiralOrder(m2);
    printList(result);
    result = s.spiralOrder(m3);
    printList(result);
    result = s.spiralOrder(m4);
    printList(result);

    return 0;
}

#endif