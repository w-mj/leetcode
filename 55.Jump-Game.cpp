#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int check[n] = {1};
        for (int i = 0; i < n; i++) {
            if (check[i] == 0 || nums[i] <= check[i] - 1)
                continue;
            if (i + nums[i] >= n - 1)
                return true;
            for (int j = 1; j <= nums[i]; j++)
                check[i + j] = nums[i] - j + 1;
        }
        return check[n - 1];
    }
};

int main(void) {
    Solution s;
    vector<int> in1 = { 3, 2, 1, 1, 1, 1, 4 };
    vector<int> in2 = { 3, 2, 1, 0, 4 };
    cout << s.canJump(in1) << endl;
    cout << s.canJump(in2) << endl;
    return 0;
}

#endif