#include "defines.h"

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top[7] = {};
        int bot[7] = {};
        int same[7] = {};
        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i]) {
                same[tops[i]]++;
            } else {
                top[tops[i]]++;
                bot[bottoms[i]]++;
            }
        }
        int ans = n;
        for (int i = 1; i <= 6; i++) {
            if (top[i] + bot[i] + same[i] == n) {
                ans = min(ans, min(top[i], bot[i]));
            }
        }
        if (ans == n) {
            return -1;
        }
        return ans;
    }
};