#include "defines.h"


class Solution {
public:
    bool equal(vector<int>& arr, int i1, int j1, int i2, int j2) {
        while (i1 < j1 && i2 < j2) {
            if (arr[i1] != arr[i2]) {
                return false;
            }
            i1++;
            i2++;
        }
        return true;
    }
    vector<int> threeEqualParts(vector<int>& arr) {
        int cnt1 = accumulate(arr.begin(), arr.end(), 0);
        if (cnt1 % 3 != 0) {
            return {-1, -1};
        }
        if (cnt1 == 0) {
            return {0,2};
        }

        int targetOnes = cnt1 / 3;
        int n = arr.size();

        // i1, j1 marks the index of the first and last one in the first block of 1s, etc.
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        
        //Find the index of the first and last 1 in each block of ones.
        int oneCount = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                oneCount += 1;
                if (oneCount == 1) i1 = i;
                if (oneCount == targetOnes) j1 = i;
                if (oneCount == targetOnes + 1) i2 = i;
                if (oneCount == 2 * targetOnes) j2 = i;
                if (oneCount == 2 * targetOnes + 1) i3 = i;
                if (oneCount == 3 * targetOnes) j3 = i;
            }
        }

        if (!equal(arr, i1, j1 + 1, i2, j2 + 1) || !equal(arr, i2, j2 + 1, i3, j3 + 1)) {
            return {-1, -1};
        }

        // The number of zeros after the left, middle, and right parts
        int trailingZerosLeft = i2 - j1 - 1;
        int trailingZerosMid = i3 - j2 - 1;
        int trailingZeros = n - j3 - 1;

        if (trailingZeros > min(trailingZerosLeft, trailingZerosMid)) {
            return {-1, -1};
        }
        return {j1 + trailingZeros, j2 + trailingZeros + 1};
    }
};