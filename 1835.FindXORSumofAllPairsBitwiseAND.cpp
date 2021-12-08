#include "defines.h"

class Solution {
public:
    inline int bit_1(int n, int bit) {
        return (n & (1 << bit)) > 0? 1: 0;
    }

    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        constexpr int n = sizeof(int) * 8;
        int cntA[n] = {0}, cntB[n] = {0};
        for (int i: arr1) {
            for (int j = 0; j < n; j++) {
                cntA[j] += bit_1(i, j);
            }
        }
        for (int i: arr2) {
            for (int j = 0; j < n; j++) {
                cntB[j] += bit_1(i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans |= (cntA[i] & cntB[i] & 1) << i;
        }
        return ans;
    }
};