#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, n = nums.size();
        int max1 = 0;
        while (i < n) {
            if (nums[i] == 0) {
                i++;
            } else {
                int s = i;
                while (i < n && nums[i] == 1) {
                    i++;
                }
                max1 = max(max1, i - s);
            }
        }
        return max1;
    }
};
int main(void) {
    Solution s;
    return 0;
}

#endif