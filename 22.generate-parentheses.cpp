/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.12%)
 * Total Accepted:    303.2K
 * Total Submissions: 569.8K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        char buf[2 * n + 10] = {0};
        vector<string> result;
        recurse(result, buf, 0, 0, n);
        return result;
    }

    void recurse(vector<string>& result, char* buf, int sp, int i, int n) {
        if (i == 2 * n) {
            result.emplace_back(buf);
            return;
        }
        if (sp + (i - sp) / 2 < n) {
            buf[i] = '(';
            recurse(result, buf, sp + 1, i + 1, n);
        }
        if (sp > 0) {
            buf[i] = ')';
            recurse(result, buf, sp - 1, i + 1, n);
        }
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<string> ou = s.generateParenthesis(5);
    for (const auto& s: ou) {
        cout << s << endl;
    }
    return 0;
}

#endif

