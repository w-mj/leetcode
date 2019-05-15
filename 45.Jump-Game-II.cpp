#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int cov = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (i > last) {
                last = cov;
                cnt++;
            }
            cov = max(cov, i + nums[i]);
        }
        return cnt;
    }
};

int main(void) {
    Solution s;
    vector<int> in = {5,3,1,1,1,4};
    cout << s.jump(in) << endl;
    return 0;
}

#endif