#include "defines.h"

class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
        vector<vector<int>> mp(101);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (int q = 0; q < queries.size(); q++) {
            int prev = -1, d = INT_MAX;
            int l = queries[q][0], r = queries[q][1];
            for (int i = 1; i <= 100; i++) {
                if (!mp[i].empty()) {
                    int k = (lower_bound(mp[i].begin(), mp[i].end(), l) - mp[i].begin());
                    if (k == mp[i].size() || mp[i][k] > r)
                        continue;
                    if (prev != -1)
                        d = min(d, i - prev);
                    if (d == 1)
                        break;
                    prev = i;
                }
            }
            ans.push_back((d == INT_MAX) ? -1 : d);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> n;
    vector<vector<int>> q;
    n = getVectorOfInt("[1,3,4,8]");
    q = getVectorOfVectorOfInt("[[0,1],[1,2],[2,3],[0,3]]");
    printList(s.minDifference(n, q));
    n = getVectorOfInt("[4,5,2,2,7,10]");
    q = getVectorOfVectorOfInt("[[2,3],[0,2],[0,5],[3,5]]");
    printList(s.minDifference(n, q));
}