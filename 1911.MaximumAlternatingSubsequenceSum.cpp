#include "defines.h"

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long prevEvenMax = 0;
        long long prevOddMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            long long temp = prevOddMax;
            prevOddMax = max(prevOddMax, prevEvenMax + nums[i]);
            prevEvenMax = max(prevEvenMax, temp - nums[i]);
        }
        return prevOddMax;
    }
};

