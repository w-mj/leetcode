#include "defines.h"

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int> > l;
        size_t i;
        for (i = 0; i < s.size();) {
            char c = s[i];
            l.emplace_back(make_pair(c, 1));
            i++;
            while (c == s[i]) {
                l.back().second++;
                i++;
            }
        }

        bool finish = false;
        while (!finish) {
            finish = true;
            for (auto iter = l.begin(); iter != l.end();) {
                if (iter->second >= k) {
                    iter->second = iter->second % k;
                    finish = false;
                }
                if (iter->second == 0) {
                    // cout << n_iter->first << iter->first <<p_iter->first << endl;
                    if (iter == l.begin() || (iter + 1) == l.end()) {
                        l.erase(iter);
                    } else if ((iter - 1)->first == (iter + 1)->first) {
                        (iter - 1)->second += (iter + 1)->second;
                        l.erase(iter);
                        l.erase(iter);
                    } else {
                        l.erase(iter);
                    }
                }
                else
                    iter++;
            }
        }
        string ans;
        for (auto x: l) {
            while (x.second--)
                ans.push_back(x.first);
        }
        return ans;
    }
};

int main(void) {
    auto s1 = "abcd";
    auto k1 = 2;
    auto s2 = "deeedbbcccbdaa";
    auto k2 = 3;
    auto s3 = "pbbcggttciiippooaais";
    auto k3 = 2;
    Solution s;
    cout << s.removeDuplicates(s1, k1) << endl;
    cout << s.removeDuplicates(s2, k2) << endl;
    cout << s.removeDuplicates(s3, k3) << endl;
}