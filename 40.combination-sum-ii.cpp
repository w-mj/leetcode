/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.12%)
 * Total Accepted:    203.3K
 * Total Submissions: 504.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#ifdef LOCAL_DEBUG
#include "defines.h"
#endif

class Solution {
public:
    void recursive(const vector<int>& candidates, int target, int index, int sum,
        vector<int>& temp, vector<vector<int>>& result)
    {
        if (target == sum) {
            // if (find(result.begin(), result.end(), temp) == result.end())
                result.push_back(temp);
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i] == candidates[i - 1])
                continue;
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                recursive(candidates, target, i + 1, sum + candidates[i], temp, result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> result;
        recursive(candidates, target, 0, 0, temp, result);
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void)
{
    Solution s;
    vector<int> in1 = { 10, 1, 2, 7, 6, 1, 5 };
    vector<int> in2 = { 2, 5, 2, 1, 2 };
    vector<vector<int>> result;
    result = s.combinationSum2(in1, 8);
    for (auto& c : result)
        printList(c);
    cout << endl;
    result = s.combinationSum2(in2, 5);
    for (auto& c : result)
        printList(c);
    return 0;
}

#endif
