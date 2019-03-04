/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (40.50%)
 * Total Accepted:    286.6K
 * Total Submissions: 704.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k, n = nums.size(), s;
        int result = 0x3f3f3f3f;
        for (i = 0; i < n - 2; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                s = nums[i] + nums[j] + nums[k];
                if (target == s)
                    return s;
                if (abs(result - target) > abs(s - target)) {
                    result = s;
                }
                if (s > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> v = { -1, 0, 1, 2, -1, -4 };
    cout << s.threeSumClosest(v, 0);
    return 0;
}

#endif

