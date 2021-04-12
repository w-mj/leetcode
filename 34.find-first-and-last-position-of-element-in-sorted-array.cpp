/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.96%)
 * Total Accepted:    271.7K
 * Total Submissions: 822.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getLeft(vector<int>& nums, int a, int b, int target) {
        int k;
        if (nums[a] == target)
            return a;
        while (a <= b) {
            k = a + (b - a) / 2;
            if (nums[k] == target && nums[k + 1] == target)
                b = k - 1;
            else if (nums[k] < target && nums[k + 1] < target) 
                a = k + 1;
            else
                return k + 1;
        }
        return -1;
    }

    int getRight(vector<int>& nums, int a, int b, int target) {
        int k;
        if (nums[b] == target)
            return b;
        while (a <= b) {
            k = a + (b - a) / 2;
            if (nums[k] == target && nums[k + 1] == target)
                a = k + 1;
            else if (nums[k] > target && nums[k + 1] > target)
                b = k - 1;
            else
                return k;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int n = nums.size();
        int a = 0, b = n - 1, k;
        while (a <= b) {
            k = a + (b - a) / 2;
            if (nums[k] < target)
                a = k + 1;
            else if (nums[k] > target)
                b = k - 1;
            else {
                if (k == 0)
                    result[0] = 0;
                else
                    result[0] = getLeft(nums, 0, k, target);
                if (k == n - 1)
                    result[1] = k;
                else
                    result[1] = getRight(nums, k, n - 1, target);
                return result;
            }
        }
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> in = { 1, 1, 2 };
    vector<int> out;
    out = s.searchRange(in, 1);
    cout << out[0] << ' ' << out[1] << " == ";
    return 0;
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        in.clear();
        int n = rand() % 100 + 1;
        for (int j = 0; j < n; j++)
            in.emplace_back(rand() % n);
        sort(in.begin(), in.end());
        int target = rand() % n;
        cout << "n = " << n << ": ";
        out = s.searchRange(in, target);
        cout << out[0] << ' ' << out[1] << " == ";
        bool print = false;
        for (int j = 0; j < n; j++) {
            if (j != n - 1) {
                if (in[j] != target && in[j + 1] == target) {
                    cout << j + 1 << ' ';
                    print = true;
                }
                if (in[j] == target && in[j + 1] != target) {
                    cout << j << " ." << endl;
                    print = true;
                }
            } else {
                if (in[j] == target) {
                    cout << j << " ." << endl;
                    print = true;
                }
            }
        }
        if (!print) {
            cout << "-1 -1 .\n";
        }
    }
    
    return 0;
}

#endif

