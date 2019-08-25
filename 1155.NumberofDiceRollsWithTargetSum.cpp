#include "defines.h"

class Solution {
public:
    int diceans[30];
    map<string, long> hash;
    int numRollsToTarget(int d, int f, int target, int from = 1, int dice = 0) {
        if (target < d)
            return 0;
        if (d == 1)
            return f >= target?1:0;
        stringstream ks;
        ks << d << target <<from <<dice;
        string k = ks.str();
        if (hash.find(k) != hash.end())
            return hash[k];
        int ans = 0;
        for (int i = 0; i <= f && i < target; i++) {
            diceans[dice] = i;
            ans += ((d - dice - 1) * (numRollsToTarget(d - 1, f, target - i, i, dice + 1))% int(1e9+7)) % int(1e9+7);
        }
        ans = ans % int(1e9+7);
        hash.emplace(k, ans);
        return ans;
    }
};

int main(void) {
    Solution s;
    cout << s.numRollsToTarget(1, 6, 3) << endl;
    cout << s.numRollsToTarget(2, 6, 7) << endl;
    cout << s.numRollsToTarget(2, 5, 10) << endl;
    cout << s.numRollsToTarget(1, 2, 3) << endl;
    cout << s.numRollsToTarget(30, 30, 500) << endl;
}