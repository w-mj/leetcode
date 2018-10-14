#include "defines.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> f(s.size() + 1);
        f[0].push_back(0);
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (!f[j].empty() && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                    f[i].push_back(j);
            }
        }
        vector<string> ans;
        stack<pair<int, string>> ss;
        for (int i: f[s.size()])
            ss.push(make_pair(i, s.substr(i, s.size() - i)));
        while (!ss.empty()) {
            pair<int, string> p = ss.top();
            ss.pop();
            if (p.first == 0) 
                ans.push_back(p.second);
            else
            for (int i: f[p.first])
                ss.push(make_pair(i, s.substr(i, p.first - i) + " " + p.second));
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<string> v = {"apple", "pen", "applepen", "pine", "pineapple"};
    auto a = s.wordBreak("pineapplepenapple", v);
    for (auto s: a) 
        cout << s << endl;
    return 0;
}