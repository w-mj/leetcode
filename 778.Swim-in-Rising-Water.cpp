#ifdef LOCAL_DEBUG
#include "defines.h"

struct MinNum {
    int x;
    int y;
    int elevation;
    MinNum(int x, int y, int e): x(x), y(y), elevation(e) {}
    bool operator<(const MinNum& ano) const {
        return elevation > ano.elevation;
    }
};

#define mk_num(x, y) MinNum(x, y, grid[x][y])
#define not_vis(x, y) (vis.find(make_pair(x, y)) == vis.end())
#define push_qu(x, y) qu.push(MinNum(x, y, max(grid[x][y], t.elevation)))

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int tar = N - 1;
        priority_queue<MinNum> qu;
        set<pair<int, int>> vis;
        qu.push(mk_num(0, 0));
        while (!qu.empty()) {
            MinNum t = qu.top();
            qu.pop();
            if (t.x == tar && t.y == tar)
                return t.elevation;
            vis.insert(make_pair(t.x, t.y));
            if (t.x > 0 && not_vis(t.x - 1, t.y))
                push_qu(t.x - 1, t.y);
            if (t.y > 0 && not_vis(t.x, t.y - 1))
                push_qu(t.x, t.y - 1);
            if (t.x < tar && not_vis(t.x + 1, t.y))
                push_qu(t.x + 1, t.y);
            if (t.y < tar && not_vis(t.x, t.y + 1))
                push_qu(t.x, t.y + 1);
        }
        return -1;
    }
};
int main(void) {
    Solution s;
    vector<vector<int>> i1 = {{0,2},{1,3}};
    vector<vector<int>> i2 = 
    {
        {0,  1, 2, 3, 4},
        {98,23,22,21, 5},
        {12,99,14,15,23},
        {11,17,99,99,99},
        {10, 9, 8, 7, 6}
    };
    // cout << s.swimInWater(i1) << endl;
    cout << s.swimInWater(i2) << endl;

    return 0;
}

#endif