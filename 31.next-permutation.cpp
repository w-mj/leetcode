/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.03%)
 * Total Accepted:    216.3K
 * Total Submissions: 719.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 1)
            return;
        if (n == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i < 0)
            i = 0;
        int k = i + 1;
        int mini = k;
        for (; k < n; k++) {
            if (nums[k] > nums[i] && nums[k] < nums[mini])
                mini = k;
        }
        if (nums[mini] > nums[i]) {
            swap(nums[i], nums[mini]);
            sort(nums.begin() + i + 1, nums.end());
        }else {
            sort(nums.begin(), nums.end());
        }
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> in1 = { 1, 2, 3 };
    vector<int> in2 = { 1, 3, 2 };
    vector<int> in3 = { 2, 1, 3 };
    vector<int> in4 = { 2, 3, 1 };
    vector<int> in5 = { 3, 1, 2 };
    vector<int> in6 = { 3, 2, 1 };
    vector<int> in7 = { 2, 2, 7, 5, 4, 3, 2, 2, 1 };
    s.nextPermutation(in1);
    s.nextPermutation(in2);
    s.nextPermutation(in3);
    s.nextPermutation(in4);
    s.nextPermutation(in5);
    s.nextPermutation(in6);
    s.nextPermutation(in7);

    for (int c: in1)
        cout << c << ' ';
    cout << endl;
    for (int c : in2)
        cout << c << ' ';
    cout << endl;
    for (int c : in3)
        cout << c << ' ';
    cout << endl;
    for (int c : in4)
        cout << c << ' ';
    cout << endl;
    for (int c : in5)
        cout << c << ' ';
    cout << endl;
    for (int c : in6)
        cout << c << ' ';
    cout << endl;
    for (int c : in7)
        cout << c << ' ';
    cout << "====[2,3,1,2,2,2,4,5,7]" << endl;
     return 0;
}

#endif

