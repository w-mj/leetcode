/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.39%)
 * Total Accepted:    486.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define MAP_CONTAINS(m, k) (m.find(k) != m.end())

class Solution {
public:
    struct Trip {
        int a, b, c;
        Trip(int aa, int bb, int cc)
        {
            a = min(aa, min(bb, cc));
            c = max(aa, max(bb, cc));
            b = aa + bb + cc - a - c;
        }
        bool operator<(const Trip& ano) const
        {
            if (a < ano.a)
                return true;
            if (b < ano.b)
                return true;
            if (c < ano.c)
                return true;
            return false;
        }
        bool operator==(const Trip& ano) const
        {
            return a == ano.a && b == ano.b && c == ano.c;
        }
    };
    set<int> twoSum(map<int, int>& m, int target)
    {
        set<int> result;
        for (auto x = m.begin(); x != m.end(); x++) {
            if (x->second == 0)
                continue;
            x->second -= 1;
            if (MAP_CONTAINS(m, target - x->first) && m[target - x->first] > 0)
                result.insert(x->first);
            x->second += 1;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        map<int, int> m;
        vector<vector<int>> result;
        set<tuple<int, int, int>> trips;
        int a, b, c, aa, bb, cc;
        for (size_t i = 0; i < nums.size(); i++) {
            if (!MAP_CONTAINS(m, nums[i]))
                m.emplace(nums[i], 0);
            m[nums[i]] += 1;
        }

        for (auto x = m.begin(); x != m.end(); x++) {
            x->second -= 1;
            set<int> se = twoSum(m, 0 - x->first);
            if (se.size() != 0) {
                for (auto sex = se.begin(); sex != se.end(); sex++) {
                    // Trip t(x->first, *sex, 0 - x->first - (*sex));
                    aa = x->first;
                    bb = *sex;
                    cc = 0 - aa - bb;
                    a = min(aa, min(bb, cc));
                    c = max(aa, max(bb, cc));
                    b = aa + bb + cc - a - c;
                    auto t = make_tuple(a, b, c);
                    trips.emplace(t);
                }
            }
            x->second += 1;
        }

        for (auto x = trips.begin(); x != trips.end(); x++) {
            vector<int> t; // = { get<0>(x), get<1>(x), get<2>(x) };
            t.emplace_back(get<0>(*x));
            t.emplace_back(get<1>(*x));
            t.emplace_back(get<2>(*x));

            result.emplace_back(t);
        }
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void)
{
    Solution s;
    vector<int> in = { 3, 0, -2, -1, 1, 2 };
    vector<vector<int>> out = s.threeSum(in);
    for (auto a : out) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
    return 0;
}

#endif
