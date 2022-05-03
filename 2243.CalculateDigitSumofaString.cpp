#include "defines.h"
#include <sstream>


class Solution {
public:
    int cal(string& s, int start, int k) {
        int ans = 0;
        for (int i = 0; i < k && start + i < s.size(); i++) {
            ans += s[start + i] - '0';
        }
        return ans;
    }

    string digitSum(string s, int k) {
        if (s.size() <= k) {
            return s;
        }
        stringstream ss;
        for (int i = 0; i < s.size(); i += k) {
            ss << cal(s, i, k);
        }
        string ans = ss.str();
        return digitSum(ans, k);
    }
};