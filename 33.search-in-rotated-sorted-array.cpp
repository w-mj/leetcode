/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.63%)
 * Total Accepted:    374.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int i, int j) {
        while (i <= j) {
            int k = i + (j - i) / 2;
            if ((k == i || nums[k] < nums[k - 1]) && (k == j || nums[k] < nums[k + 1]))
                return k;
            if (nums[k] > nums[j])
                i = k + 1;
            else
                j = k - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int i, int j, int target)
    {
        while (i <= j) {
            int k = i + (j - i) / 2;
            if (nums[k] == target)
                return k;
            if (nums[k] > target) 
                j = k - 1;
             else 
                i = k + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int p, r;
        p = search(nums, 0, n - 1);
        r = search(nums, 0, p - 1, target);
        if (r == -1)
            r = search(nums, p, n - 1, target);
        return r;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> in = {100, 9, 20, 8, 1, 3, 4, 5, 6, 7};
    cout << s.search(in, 0) << endl;
    cout << s.search(in, 3) << endl;
    return 0;
}

#endif

