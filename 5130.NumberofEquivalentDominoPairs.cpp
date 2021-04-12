#include "defines.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> se;
        int ans = 0;
        for (const auto& x: dominoes) {
            auto p1 = make_pair(x[0], x[1]);
            if (x[0] > x[1])
                swap(p1.first, p1.second);
            if (se.find(p1) == se.end()) {
                se.insert(make_pair(p1, 1));
            } else {
                se[p1] += 1;
            }
        }
        for (auto& x: se) {
            x.second -= 1;
            ans += (1 + x.second) * x.second / 2;
        }
        return ans;
    }
};

