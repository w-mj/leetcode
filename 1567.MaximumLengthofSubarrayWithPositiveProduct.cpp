#include "defines.h"

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        bool evenNegatives = true;
        int firstNegative = -1;
        int lastNegative = -1;
        int start = 0;
        int ans = 0;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (evenNegatives) {
                    ans = max(ans, i - start);
                } else {
                    ans = max(ans, max(i - firstNegative - 1, lastNegative - start));
                }
                start = i + 1;
                firstNegative = -1;
                lastNegative = -1;
                evenNegatives = true;
            } else if (nums[i] < 0) {
                evenNegatives = !evenNegatives;
                if (firstNegative == -1) {
                    firstNegative = i;
                }
                lastNegative = i;
            }
        }
        return ans;
    }
};