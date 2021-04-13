#include "defines.h"



class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int direction[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        vector<int> cur = {r0, c0};
        int cnt = R * C;
        int dir = 0;
        int moves = 1;
        ans.push_back(cur);
        while (ans.size() != R * C) {
            for (int t = 0; t < 2; t++) {
                for (int i = 0; i < moves; i++) {
                    cur[0] += direction[dir][0];
                    cur[1] += direction[dir][1];
                    if (cur[0] >= 0 && cur[0] < R && cur[1] >= 0 && cur[1] < C) {
                        ans.push_back(cur);
                    }
                }
                dir = (dir + 1) % 4;
            }
            moves++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    printList(s.spiralMatrixIII(5, 6, 1, 4));
}