#include "defines.h"


struct Pos {
    int xt;
    int yt;
    int xh;
    int yh;
    int cnt = 0;
    Pos(int xt, int yt, int xh, int yh, int cnt=0): xt(xt), yt(yt), xh(xh), yh(yh), cnt(cnt) {}
    bool operator<(const Pos& ano) const {
        return ano.cnt < cnt;
    }
};
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        size_t n = grid.size();
        if (grid[n - 1][n - 2] + grid[n - 1][n - 1] > 0)
            return -1;
        priority_queue<Pos> q;
        q.emplace(0, 0, 0, 1);
        vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(n, make_pair(0, 0)));
        while (!q.empty()) {
            auto cur = q.top();
            q.pop();
            if (cur.xh == cur.xt) {
                if (vis[cur.xt][cur.yt].first == 1)
                    continue;
                vis[cur.xt][cur.yt].first = 1;
            }
            else if (cur.yh == cur.yt) {
                if (vis[cur.xt][cur.yt].second == 1)
                    continue;
                vis[cur.xt][cur.yt].second = 1;
            }
            if (cur.xt == n - 1 && cur.yt == n - 2 && cur.xh == n - 1 && cur.yh == n - 1) {
                return cur.cnt;
            }
            if (cur.xt == cur.xh) {
                // horizantal
                if (cur.yh < n - 1 && grid[cur.xh][cur.yh + 1] == 0) {
                    q.emplace(cur.xt, cur.yt+1, cur.xh, cur.yh+1, cur.cnt+1);
                }
                if (cur.xh < n - 1 && grid[cur.xt + 1][cur.yt] + grid[cur.xt + 1][cur.yh] == 0) {
                    q.emplace(cur.xt + 1, cur.yt, cur.xh + 1, cur.yh, cur.cnt+1);
                    q.emplace(cur.xt, cur.yt, cur.xt + 1, cur.yt, cur.cnt+1);
                }
            } else if (cur.yt == cur.yh) {
                // vertical
                if (cur.xh < n - 1 && grid[cur.xh + 1][cur.yh] == 0) {
                    q.emplace(cur.xt + 1, cur.yt, cur.xh + 1, cur.yh, cur.cnt+1);
                }
                if (cur.yh < n - 1 && grid[cur.xt][cur.yh + 1] + grid[cur.xh][cur.yt + 1] == 0) {
                    q.emplace(cur.xt, cur.yt + 1, cur.xh, cur.yh + 1, cur.cnt + 1);
                    q.emplace(cur.xt, cur.yt, cur.xt, cur.yt + 1, cur.cnt+1);
                }
            }
        }
        return -1;
    }
};

int main(void) {

}