#include "defines.h"

class Solution {
public:
    vector<vector<int>> cache[20];
    vector<vector<int>> *graph;
    void func(int cur) {
        if (cache[cur].size() > 0) {
            return;
        }
        vector<vector<int>> &ans = cache[cur];
        for (int next: graph->at(cur)) {
            if (next == graph->size() - 1) {
                ans.push_back(vector<int>{next});
            } else {
                func(next);
                for (auto & x: cache[next]) {
                    ans.emplace_back(x);
                }
            }
        }
        for (auto &x: ans) {
            x.insert(x.begin(), cur);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        for (int i = 0; i < 20; i++) {
            cache[i].clear();
        }
        this->graph = &graph;
        func(0);
        return cache[0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> g;
    g = getVectorOfVectorOfInt("[[1,2],[3],[3],[]]");
    cout << s.allPathsSourceTarget(g) << endl;
    g = getVectorOfVectorOfInt("[[4,3,1],[3,2,4],[3],[4],[]]");
    cout << s.allPathsSourceTarget(g) << endl;
    g = getVectorOfVectorOfInt("[[1],[]]");
    cout << s.allPathsSourceTarget(g) << endl;
    g = getVectorOfVectorOfInt("[[1,2,3],[2],[3],[]]");
    cout << s.allPathsSourceTarget(g) << endl;
    g = getVectorOfVectorOfInt("[[1,3],[2],[3],[]]");
    cout << s.allPathsSourceTarget(g) << endl;
}