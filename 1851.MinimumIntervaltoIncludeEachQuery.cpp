#include "defines.h"


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> qu;
        for (int i = 0; i < queries.size(); ++i) {
            qu.emplace_back(make_pair(queries[i], i));
        }
        sort(qu.begin(), qu.end());

        vector<int> ans(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        int i = 0;
        for (auto &kk : qu) {
            int q = kk.first;
            int index = kk.second;
            while (i < intervals.size() && intervals[i][0] <= q) {
                queue.push(make_pair(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]));
                i++;
            }
            while (!queue.empty() && queue.top().second < q) {
                queue.pop();
            }
            if (!queue.empty()) {
                ans[index] = queue.top().first;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    // vector<pair<int, int>> v;
    // for (int i = 0; i < 10; i++) {
    //     v.push_back(make_pair(i * 3 + 4, 0));
    // }
    // for (int i = 0; i < 40; i++) {
    //     cout << i << "  :  " << s.binsearch(v, i) << endl;
    // }

    vector<vector<int>> vvi = getVectorOfVectorOfInt("[[1,4],[2,4],[3,6],[4,4]]");
    vector<int> vi = getVectorOfInt("[2,3,4,5]");
    cout << s.minInterval(vvi, vi) << endl;
    vvi = getVectorOfVectorOfInt("[[2,3],[2,5],[1,8],[20,25]]");
    vi = getVectorOfInt("[2,19,5,22]");
    cout << s.minInterval(vvi, vi) << endl;
}