#ifdef LOCAL_DEBUG
#include "defines.h"
// class Solution {
// public:
//     pair<int, int> counter(const string& s) {
//         pair<int, int> ans = {0, 0};
//         for (auto c: s) {
//             if (c == '0')
//                 ans.first++;
//             else
//                 ans.second++;
//         }
//         return ans;
//     }

//     int maxi = 0;
//     int dfs(const vector<pair<int, int>>& tasks,int m, int n, int i, int cm) {
//         int ans = 0;
//         if (i == tasks.size()) {
//             maxi = max(maxi, cm);
//             return 0;
//         }
//         if (m == 0 && n == 0) {
//             maxi = max(maxi, cm);
//             return 0;
//         }
//         if (cm + tasks.size() - i < maxi) {
//             maxi = max(maxi, cm);
//             return 0;
//         }
//         if (m < tasks[i].first) {
//             maxi = max(maxi, cm);
//             return 0;
//         }
//         int a = dfs(tasks, m, n, i + 1, cm);
//         int b = 0;
//         if (m >= tasks[i].first && n >= tasks[i].second) {
//             b = dfs(tasks, m - tasks[i].first, n - tasks[i].second, i + 1, cm + 1);
//         }
//         // maxi = max(maxi, max(a, b + 1));
//         return 0 ;//max(a, b + 1);
//     }
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         vector<pair<int, int>> tasks;
//         for (auto& s: strs)
//             tasks.emplace_back(counter(s));
//         sort(tasks.begin(), tasks.end());
//         maxi = 0;
//         dfs(tasks, m, n, 0, 0);
//         return maxi;
//     }
// };

class Solution {
public:
    pair<int, int> counter(const string& s) {
        pair<int, int> ans = {0, 0};
        for (auto c: s) {
            if (c == '0')
                ans.first++;
            else
                ans.second++;
        }
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1] = {0};
        memset(dp, 0, sizeof(dp));
        for (const auto& s: strs) {
            pair<int, int> t = counter(s);
            for (int i = m; i >= t.first; i--) {
                for (int j = n; j >= t.second; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - t.first][j - t.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(void) {
    Solution s;
    vector<string> v1 = {"10", "0001", "111001", "1", "0"};
    vector<string> v2 = {"10", "0", "1"};
    vector<string> v3 = {"0","0","0","0","0","1","1","0","1","1","1","0","1","0","1","1","0","0","1","0","1","1","0","1","1","1","1","1","0","1","1","1","1","1","1","0","1","1","0","0","0","0","1","1","0","1"};

    cout << s.findMaxForm(v1, 5, 3) << endl;
    cout << s.findMaxForm(v2, 1, 1) << endl;
    cout << s.findMaxForm(v3, 52, 12) << endl;
    return 0;
}

#endif