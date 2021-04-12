#include "defines.h"

class Solution {
public:
    int getparent(vector<int> & s, int i ) {
        int ans = s[i];
        if (ans != i) {
            ans = getparent(s, ans);
            s[i] = ans;
        }
        return ans;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        size_t n = s.size();
        vector<int> dset(s.size(), 0);
        for (size_t i = 0; i < s.size(); i++) 
            dset[i] = i;
        for (auto &p: pairs) {
            dset[getparent(dset, p[0])] = getparent(dset, p[1]);
        }
        map<int, string> m;
        for (size_t i = 0; i < n; i++) {
            int group = getparent(dset, i);
            if (m.find(group) == m.end()) 
                m.emplace(group, "");
            m[group].push_back(s[i]);
        }
        for (auto& x: m) {
            sort(x.second.begin(), x.second.end());
        }
        string ans;
        for (size_t i = 0; i < n; i++) {
            int group = getparent(dset, i);
            ans.push_back(m[group].front());
            m[group].erase(m[group].begin());
        }
        return ans;
    }
};