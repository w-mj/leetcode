/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.36%)
 * Total Accepted:    348.6K
 * Total Submissions: 862.8K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char key_map[10][5] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0)
            return result;
        char t[10] = {0};
        recurse(t, result, digits, 0);
        return result;
    }

    void recurse(char t[10], vector<string>& result, const string digits, int i) {
        char *c = key_map[digits[i] - '0'];
        while (*c) {
            t[i] = *c;
            if (i != digits.size() - 1) {
                recurse(t, result, digits, i + 1);
            } else {
                result.emplace_back(t);
            }
            c++;
        }
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<string> r = s.letterCombinations("23");
    for (auto& x: r) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

#endif

