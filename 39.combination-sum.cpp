/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (46.65%)
 * Total Accepted:    309.8K
 * Total Submissions: 660.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
        vector<int>& temp, vector<vector<int>>& result) {
        if (target == sum) {
            result.push_back(temp);
        }
        for (int i = index; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                recursive(candidates, target, i, sum + candidates[i], temp, result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> result;
        recursive(candidates, target, 0, 0, temp, result);
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result;
//         vector<int>::iterator search = find(candidates.begin(), candidates.end(), target);
//         if (search != candidates.end()) {
//             result.emplace_back(vector<int>{*search});
//         } 
//         for (int c: candidates) {
//             if (target > c) {
//                 vector<vector<int>> recurse_result = combinationSum(candidates, target - c);
//                 for (vector<int>& v: recurse_result) {
//                     v.insert(v.begin(), c);
//                     sort(v.begin(), v.end());
//                     if (find(result.begin(), result.end(), v) == result.end())
//                         result.emplace_back(v);
//                 }
//             }
//         }
//         return result;
//     }
// };

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<int> in1 = {2, 3, 6, 7};
    vector<int> in2 = {2, 3, 5};
    vector<vector<int>> result;
    result = s.combinationSum(in1, 7);
    for (auto& c: result)
        printList(c);
    cout << endl;
    result = s.combinationSum(in2, 8);
    for (auto& c : result)
        printList(c);
    return 0;
}

#endif

