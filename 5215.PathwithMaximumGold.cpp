#include "defines.h"

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(20, vector<bool>(20, false));
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (!vis[i][j] && grid[i][j]) {
                    queue<pair<int, int>> qu;
                    qu.emplace(i, j);
                    while (!qu.empty()) {
                        auto p = qu.front();
                        qu.pop();
                        int x = p.first;
                        int y = p.second;
                        if (vis[x][y])
                            continue;
                        vis[x][y] = true;
                        if (x > 0 && grid[x - 1][y]) {
                            if (!vis[x - 1][y])
                            grid[x - 1][y] += grid[x][y];
                            qu.emplace(x - 1, y);
                        }
                        if (x < m - 1 && grid[x + 1][y] ) {
                            if (!vis[x+1][y])

                            grid[x + 1][y] += grid[x][y];
                            qu.emplace(x + 1, y);
                        }
                        if (y > 0 && grid[x][y - 1] ) {
                            if (!vis[x][y-1])

                            grid[x][y - 1] += grid[x][y];
                            qu.emplace(x, y - 1);
                        }
                        if (y < n - 1 && grid[x][y + 1]) {
                            if (!vis[x][y+1])

                            grid[x][y + 1] += grid[x][y];
                            qu.emplace(x, y + 1);
                        }
                    }
                }
            }
        }
        int manx = 0;
        for (auto &x1: grid) {
            for (auto y1: x1) {
                manx = max(manx, y1);
            }
        }
        return manx;
    }
};

int main(void) {
    vector<vector<int>> i1 = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    Solution s;
    cout << s.getMaximumGold(i1);
}