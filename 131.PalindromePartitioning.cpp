#include "defines.h"

class Solution {
public:
    bool check(const string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<int>> getSplits(int n, int sum) {
        vector<vector<int>> ans;
        if (n > sum) {
            return ans;
        } else if (n == 1) {
            ans.push_back({sum});
        } else {
            for (int i = 1; i <= sum - n + 1; i++) {
                auto tmp = getSplits(n - 1, sum - i);
                for (auto &k : tmp) {
                    if (k.size() == n - 1) {
                        k.insert(k.begin(), i);
                        ans.push_back(k);
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        for (int i = 1; i <= s.size(); i++) {
            auto split = getSplits(i, s.size());
            for (auto &a: split) {
                int start = 0;
                vector<string> tmp;
                for (int len: a) {
                    string subStr = s.substr(start, len);
                    if (check(subStr)) {
                        tmp.emplace_back(move(subStr));
                        start += len;
                    } else {
                        break;
                    }
                }
                if (start == s.size()) {
                    ans.emplace_back(move(tmp));
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.partition("aab") << endl;
    cout << s.partition("a") << endl;
}