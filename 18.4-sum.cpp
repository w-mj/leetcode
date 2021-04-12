/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (29.68%)
 * Total Accepted:    212.9K
 * Total Submissions: 716.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    tuple<int, int, int, int> make_tuple4(int a, int b, int c, int d)
    {
        if (a < b)
            swap(a, b);
        if (c < d)
            swap(c, d);
        if (a < c)
            swap(a, c);
        if (b < c)
            swap(b, c);
        if (b < d)
            swap(b, d);
        if (c < d)
            swap(c, d);
        return make_tuple(d, c, b, a);
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        set<tuple<int, int, int, int>> result_set;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i, j, k, l, n = nums.size();
        for (i = 0; i < n - 3; i++) {
            for (j = i + 1; j < n - 2; j++) {
                int t0 = target - nums[i] - nums[j];
                k = j + 1;
                l = n - 1;
                while (k < l) {
                    int r = nums[k] + nums[l];
                    if (t0 == r) {
                        result_set.emplace(make_tuple4(nums[i], nums[j], nums[k], nums[l]));
                        k++;
                        l--;
                    } else if (r < t0) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        for (auto& r : result_set) {
            vector<int> t(4, 4);
            t[0] = get<0>(r);
            t[1] = get<1>(r);
            t[2] = get<2>(r);
            t[3] = get<3>(r);
            result.emplace_back(t);
        }
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void)
{
    Solution s;
    vector<int> in = { 1, 0, -1, 0, -2, 2 };
    vector<vector<int>> ou = s.fourSum(in, 0);
    for (const auto& s: ou) {
        for (const auto& p: s) {
            cout << p << " ";
        }
        cout << endl;
    }
    return 0;
}

#endif
