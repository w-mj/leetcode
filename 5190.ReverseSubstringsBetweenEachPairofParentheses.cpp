#include "defines.h"

class Solution {
public:
    string fr(const string& s, int& i) {
        string ans;
        for (; i < s.size(); ) {
            if (s[i] == '(') {
                i++;
                string t = fr(s, i);
                reverse(t.begin(), t.end());
                ans += t;
                if (i >= s.size())
                    return ans;
            } else if (s[i] == ')') {
                i++;
                break;
            } else {
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
    string reverseParentheses(string s) {
        int i = 0;
        // if (s [0] != '(')
        //     s = "((" + s + "))";
        // while(i < s.size() && s[i] != '(')
        //     i++;
        // if (i == s.size())
        //     return s;
        // string ans = s.substr(0, i);
        // i++;
        // auto t = fr(s, i);

        // ans += t;
        // ans += s.substr(i+1);
        return fr(s, i);
    }

};