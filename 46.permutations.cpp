/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (53.35%)
 * Total Accepted:    344.8K
 * Total Submissions: 643.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
#ifdef LOCAL_DEBUG
#include "defines.h"
#endif

class Solution {
public:
    void permute(vector<int>& nums, vector<int>& temp, int index, int n, vector<bool>& flag, 
                vector<vector<int>>& result) {
        for (int i = 0; i < n; i++) {
            if (flag[i] == false) {
                flag[i] = true;
                temp[index] = nums[i];
                if (index + 1 == n)
                    result.emplace_back(temp);
                else
                    permute(nums, temp, index + 1, n, flag, result);
                flag[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp(nums.size(), 0);
        vector<bool> flag(nums.size(), false);
        permute(nums, temp, 0, nums.size(), flag, result);
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = s.permute(nums);
    printList(result);
    return 0;
}

#endif

