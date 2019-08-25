#include "defines.h"

class Solution {
public:
    string lastSubstring(string s) {
        vector<int> choices;
        char c=0;
        for (auto x: s) {
            if (x > c) 
                c = x;
        }
        for (int i  = 0; i < s.size(); i++) {
            if (s[i] == c) choices.emplace_back(i);
        }
        int expend = 1;
        while (choices.size() > 1) {
            char max_s = 0;
            for (int i= 0; i < choices.size(); i++) {
                if (choices[i] + expend >= s.size())
                    continue;
                if (s[choices[i] + expend] > max_s)
                    max_s = s[choices[i] + expend];
            }
            int i = 0;
            while (i < choices.size()) {
                if (choices[i] + expend >= s.size() || s[choices[i] + expend] != max_s) {
                    choices.erase(choices.begin() + i);
                } else {
                    i++;
                }
            }
            expend++;
        }
        if (choices.size() == 0)
            return "123";
        return s.substr(choices[0]);
    }
};

int main(void) {
    Solution s;
    cout << s.lastSubstring("abab") << endl;
    cout << s.lastSubstring("leetcode") << endl;
}