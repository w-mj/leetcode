#include "defines.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_v = 0;
        int sum_n = 0;
        for (int n: nums) {
            sum_n += n;
            min_v = min(min_v, sum_n);
        }
        return abs(min_v) + 1;
    }
};