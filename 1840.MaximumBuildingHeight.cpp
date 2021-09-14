#include "defines.h"

class Solution {
public:

    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1, 0});
        res.push_back({n, n - 1});
        sort(res.begin(), res.end());
        int m = res.size();
        
        for (int i = 1; i < m; i++) {
            res[i][1] = min(res[i][1], res[i - 1][1] + res[i][0] - res[i - 1][0]);
        }
        for (int i = m - 2; i >= 0; i--) {
            res[i][1] = min(res[i][1], res[i + 1][1] + res[i + 1][0] - res[i][0]);
        }
        int ans = 0;
        int l, h1, r, h2;
        for (int i = 1; i < m; i++) {
            l = res[i - 1][0];
            r = res[i][0];
            h1 = res[i - 1][1];
            h2 = res[i][1];
            ans = max(ans, max(h1, h2) + (r - l - abs(h1 - h2)) / 2);
        }
        return ans;
    }

};
FILE *stream;
int main(int argc, char **argv) {
    Solution s;
    int ret = freopen_s(&stream, "1840.MaximumBuildingHeight.txt", "r", stdin);
    if (ret != 0) {
        perror("freopen_s");
    }
    std::string line;
    while (getline(cin, line)) {
        int n = getInt(line.c_str(), NULL);
        getline(cin, line);
        vector<vector<int>> b = getVectorOfVectorOfInt(line.c_str(), NULL);
        // cout << n << endl;
        // cout << line << endl;
        std::cout << s.maxBuilding(n, b) << std::endl;
    }
    return 0;
}