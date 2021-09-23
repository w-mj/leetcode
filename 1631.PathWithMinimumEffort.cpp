#include "defines.h"

class Solution {
public:
    struct Pos {
        int x, y;
        int effort;
        Pos(int x, int y, int e) {
            this->x = x;
            this->y = y;
            this->effort = e;
        }
        bool operator<(const Pos& pos) const  {
            return pos.effort < effort;
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<Pos> qu;
        qu.emplace(0, 0, 0);
        int move[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!qu.empty()) {
            Pos p = qu.top();
            qu.pop();
            if (p.x == m - 1 && p.y == n - 1) {
                return p.effort;
            }
            if (vis[p.x][p.y]) {
                continue;
            }
            vis[p.x][p.y] = true;
            for (int i = 0; i < 4; i++) {
                int nX = p.x + move[i][0];
                int nY = p.y + move[i][1];
                if (!(nX >= 0 && nX < m && nY >= 0 && nY < n))
                    continue;
                int nH = abs(heights[p.x][p.y] - heights[nX][nY]);
                qu.emplace(nX, nY, max(p.effort, nH));
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    auto v = getVectorOfVectorOfInt("[[1,2,2],[3,8,2],[5,3,5]]", NULL);
    cout << s.minimumEffortPath(v) << endl;
    v = getVectorOfVectorOfInt("[[1,2,3],[3,8,4],[5,3,5]]", NULL);
    cout << s.minimumEffortPath(v) << endl;
    v = getVectorOfVectorOfInt("[[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]", NULL);
    cout << s.minimumEffortPath(v) << endl;
}