#include "defines.h"

// class Solution {
// public:
//     vector<vector<int>> ans;

//     void backtrace(vector<int>& nums, vector<bool>& mask, int i) {
//         if (i == nums.size()) {
//             vector<int> n;
//             for (int j = 0; j < mask.size(); j++) {
//                 if (mask[j] == true) {
//                     n.push_back(nums[j]);
//                 }
//             }
//             ans.push_back(std::move(n));
//             return;
//         }

//         mask[i] = true;
//         backtrace(nums, mask, i + 1);
//         mask[i] = false;
//         backtrace(nums, mask, i + 1);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         ans.clear();
//         vector<bool> mask(nums.size(), false);
//         backtrace(nums, mask, 0);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> getNumsMask(vector<int>& nums, int mask) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1 << i)) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int mask = 0; mask < (1 << nums.size()); mask++) {
            ans.push_back(getNumsMask(nums, mask));
        }
        return ans;
    }
};