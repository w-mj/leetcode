#include "defines.h"
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int, set<int>> emap;
        for (auto &x: edges) {
            emap[x[0]].insert(x[1]);
            emap[x[1]].insert(x[0]);
        }
        // for (auto x: emap) {
        //     cout << x.first << " ";
        //     printList(x.second);
        // }
        vector<int> mheights(n, n);
        for (int i = 0; i < n; i++) {
            vector<int> hh(n, -1);
            vector<bool> vis(n, false);
            hh[i] = 0;
            int maxh = -100;
            queue<int> qu;
            qu.push(i);
            while (!qu.empty()) {
                int x = qu.front();
                qu.pop();
                if (vis[x])
                    continue;
                vis[x] = true;
                maxh = max(maxh, hh[x]);
                for (auto nx: emap[x]){ 
                    if (!vis[nx]) {
                        hh[nx] = hh[x] + 1;
                        qu.push(nx);
                    }
                }
            }
            mheights[i] = maxh;
        }
        // for (auto x: mheights) {
        //     cout << x << " ";
        // }
        cout << endl;
        int mine = *min_element(mheights.begin(), mheights.end());
        vector<int> ans;
        for (size_t i = 0; i < mheights.size(); i++) {
            if (mheights[i] == mine) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(void) {
    vector<vector<int>> i1 = {{1, 0}, {1, 2}, {1, 3}};
    Solution s;
    printList(s.findMinHeightTrees(4, i1));
}