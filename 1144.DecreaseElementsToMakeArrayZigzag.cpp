#include "defines.h"

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int sum = 0;
        for (size_t i = 1; i < nums.size(); i += 2) {
            if (i < nums.size() - 1) {
                if (nums[i] >= nums[i - 1] || nums[i] >= nums[i + 1]) {
                    sum += (nums[i] - min(nums[i - 1], nums[i + 1])) + 1;
                }
            } else {
                if (nums[i] >= nums[i - 1]) {
                    sum += nums[i] - nums[i - 1] + 1;
                }
            }
        }
        int sum2 = 0;
        for (size_t i = 0; i < nums.size(); i += 2) {
            if (i == 0) {
                if (nums[i] >= nums[i + 1]) {
                    sum2 += nums[i] - nums[i + 1] + 1;
                }
            } else if (i < nums.size() - 1) {
                if (nums[i] >= nums[i - 1] || nums[i] >= nums[i + 1]) {
                    sum2 += (nums[i] - min(nums[i - 1], nums[i + 1])) + 1;
                }
            } else {
                if (nums[i] >= nums[i - 1]) {
                    sum2 += nums[i] - nums[i - 1] + 1;
                }
            }
        }
        return min(sum, sum2);
    }
};

int main(void) {
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {9,6,1,6,2};
    vector<int> v3 = {10,4,4,10,10,6,2,3};
    Solution s;
    cout << s.movesToMakeZigzag(v1) << endl;
    cout << s.movesToMakeZigzag(v2) << endl;
    cout << s.movesToMakeZigzag(v3) << endl;
}
