/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.12%)
 * Total Accepted:    224.1K
 * Total Submissions: 570K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
        vector<vector<int>>& result)
    {
        int last_pick;
        bool picked = false;
        for (int i = 0; i < n; i++) {
            if (flag[i] == false && (!picked || nums[i] != last_pick)) {
                flag[i] = true;
                picked = true;
                last_pick = temp[index] = nums[i];
                if (index + 1 == n)
                    result.emplace_back(temp);
                else
                    permute(nums, temp, index + 1, n, flag, result);
                flag[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> temp(nums.size(), 0);
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end());
        permute(nums, temp, 0, nums.size(), flag, result);
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void)
{
    Solution s;
    vector<int> nums = { 1, 1, 2, 2, 3 };
    vector<vector<int>> result = s.permuteUnique(nums);
    printList(result);
    return 0;
}

#endif

