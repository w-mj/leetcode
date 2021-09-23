#include "defines.h"

class Solution {
public:
    int maxWidthRamp(const vector<int>& nums) {
        int n[50010] = {0};
        int v[50010] = {0};
        for (int i = 0; i < 50010; i++) {
            n[i] = -1;
            v[i] = -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (v[nums[i]] == -1) {
                v[nums[i]] = i;
            }
            n[nums[i]] = i;
        }
        for (int i = 50010 - 2; i >= 0; i--) {
            n[i] = max(n[i], n[i+1]);
        }
        int ans = 0;
        for (int i = 0; i < 50010; i++) {
            if (v[i] != -1) {
                ans = max(ans, n[i] - v[i]);
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.maxWidthRamp({6,0,8,2,1,5}) << endl;
    cout << s.maxWidthRamp({9,8,1,0,1,9,4,0,4,1}) << endl;
    cout << s.maxWidthRamp({5,4,3,2,1}) << endl;
}