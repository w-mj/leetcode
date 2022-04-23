#include "defines.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i=coin; i<=amount; i++)
                dp[i] += dp[i-coin];   
        }
        return dp[amount];
    }
};


int main() {
    Solution s;
    vector<int> v;
    v = getVectorOfInt("[1,2,5]");
    cout << s.change(5, v) << endl;
}