#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int T = 0;
        while (T < n / 2) {
            for (int i = T; i < n - T - 1; i++) {
                int k = matrix[T][i];
                matrix[T][i] = matrix[n - i - 1][T];
                matrix[n - i - 1][T] = matrix[n - T - 1][n - i - 1];
                matrix[n - T - 1][n - i - 1] = matrix[i][n - T - 1];
                matrix[i][n - T - 1] = k;
            }
            T++;
        }
    }
};

int main(void) {
    Solution s;
    // vector<vector<int>> m = {
    //     { 1, 2, 3, 4, 5 },
    //     { 6, 7, 8, 9, 10 },
    //     { 11, 12, 13, 14, 15 },
    //     { 16, 17, 18, 19, 20 },
    //     { 21, 22, 23, 24, 25 } };
    vector<vector<int>> m = {
        { 5, 1, 9, 11 },
        { 2, 4, 8, 10 },
        { 13, 3, 6, 7 },
        { 15, 14, 12, 16 }
    };
    s.rotate(m);
    printList(m);
    return 0;
}

#endif