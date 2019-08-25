#include "defines.h"

#define mkp make_pair
class Solution {
public:
    int landDistance(vector<vector<int>>& grid, int wx, int wy) {
        priority_queue<pair<int, pair<int, int>>> q;
        // queue<pair<int, int>> s;
        set<pair<int, int>> vis;
        int min_d = -1;
        // s.push(make_pair(wx, wy));
        q.push(mkp(10000, mkp(wx, wy)));
        int delta[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while(!q.empty()) {
            auto aa = q.top();
            auto a = aa.second;
            q.pop();
            if (vis.find(a) != vis.end())
                continue;
            vis.emplace(a);
            int x = a.first;
            int y = a.second;
            if (grid[x][y] == 1)
                return 10000 - aa.first;
            for (int i = 0; i < 8; i++) {
                int tx = x + delta[i][0];
                int ty = y + delta[i][1];
                if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[x].size()) {
                    int d = abs(wx - tx) + abs(wy - ty);
                    q.push(mkp(10000 - d, mkp(tx, ty)));
                }
            }
        }
        return min_d;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int max_dis = -1;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == 0) {
                    int dis = landDistance(grid, x, y);
                    max_dis = max(max_dis, dis);
                }
            }
        }
        return max_dis;
    }
};

int main(void) {
    vector<vector<int>> in = 
    {
        {1,0,0,0,0,1,0,0,0,1},
        {1,1,0,1,1,1,0,1,1,0},
        {0,1,1,0,1,0,0,1,0,0},
        {1,0,1,0,1,0,0,0,0,0},
        {0,1,0,0,0,1,1,0,1,1},
        {0,0,1,0,0,1,0,1,0,1},
        {0,0,0,1,1,1,1,0,0,1},
        {0,1,0,0,1,0,0,1,0,0},
        {0,0,0,0,0,1,1,1,0,0},
        {1,1,0,1,1,1,1,1,0,0}
    };
    Solution s;
    cout << s.maxDistance(in) << endl;
}