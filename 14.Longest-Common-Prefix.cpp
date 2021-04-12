/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.
*/


#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        size_t n = strs[0].size();
        for (size_t i = 1; i < strs.size(); i++)
            n = min(n, strs[i].size());

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 1; j < strs.size(); j++) {
                if (strs[j - 1][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, n);
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif