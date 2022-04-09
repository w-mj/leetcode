#include "defines.h"


const int mod = (int)(1e9 + 7);
class Solution {
public:

    int numberWays(vector<vector<int>>& origin) {
        int arr[2][1<<11] = { 0 };
        int *back = arr[0];
        int *dp = arr[1];
        int people = origin.size();
        int hats[11][41] = {0};
        int max_h = 0;
        int max_state = (1 << people) - 1;
        // set<int> hat_set;
        for (int n = 0; n < origin.size(); n++) {
            for (int h: origin[n]) {
                hats[n][h] = 1;
                max_h = max(max_h, h);
                // hat_set.insert(h);
            }
        }
        // vector<int> hat_vec(hat_set.begin(), hat_set.end());

        back[0] = 1;
        dp[0] = 1;

        for (int h = 1; h <= max_h; h++) {
            int hat = h;
            for (int state = 1; state <= max_state; state++) {
                dp[state] = back[state];
                for (int p = 0; p < people; p++) {
                    if (hats[p][hat] == 0) {
                        continue;
                    }
                    if (state & (1 << p)) {
                        dp[state] += back[state ^ (1 << p)];
                        dp[state] %= mod;
                    }
                }
                // printf("dp[%d][%d]=%d\n", h, state, dp[state]);
            }
            swap(dp, back);
        }
        return back[max_state];
    }
};

int main() {
    Solution s;
    // auto v = getVectorOfVectorOfInt("[[1,2,4,6,7,8,9,11,12,13,14,15,16,18,19,20,23,24,25],[2,5,16],[1,4,5,6,7,8,9,12,15,16,17,19,21,22,24,25],[1,3,6,8,11,12,13,16,17,19,20,22,24,25],[11,12,14,16,18,24],[2,3,4,5,7,8,13,14,15,17,18,21,24],[1,2,6,7,10,11,13,14,16,18,19,21,23],[1,3,6,7,8,9,10,11,12,14,15,16,18,20,21,22,23,24,25],[2,3,4,6,7,10,12,14,15,16,17,21,22,23,24,25]]");
    // cout << s.numberWays(v) << "   778256459" << endl;
    auto v = getVectorOfVectorOfInt("[[3,5,1],[3,5]]");
    cout << s.numberWays(v) << endl;
}