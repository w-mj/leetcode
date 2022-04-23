#include "defines.h"

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int ans = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            ans += n & 1;
            n = n >> 1; 
        }
        return ans;
    }
};