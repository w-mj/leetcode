#include "defines.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odds = 0;
        int evens = 0;
        for (auto x: chips) {
            if (x & 1)
                ++odds;
            else
                ++evens;
        }
        return min(odds, evens);
    }
};