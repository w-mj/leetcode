#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> tree;
        set<int> start;
        for (int i = 0; i < numCourses; i++) {
            start.emplace(i);
            tree.emplace(i, vector<int>());
        }
        for (auto x: prerequisites) {
            tree[x[0]].emplace_back(x[1]);
        }

        vector<int> ans;
        set<int> over;
        bool finish = false;
        while (!finish) {
            finish = true;
            if (start.empty())
                return ans;
            for (auto i = start.begin(); i != start.end(); i++) {
                bool is = true;
                for (auto x: tree[*i]) {
                    if (over.find(x) == over.end()) {
                        is = false;
                        break;
                    }
                }
                if (is) {
                    ans.push_back(*i);
                    over.emplace(*i);
                    finish = false;
                    start.erase(i);
                    break;
                }
            }
        }
        return {};
    }
};
int main(void) {
    Solution s;
    return 0;
}

#endif