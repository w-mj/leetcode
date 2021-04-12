#include "defines.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            int s = 0;
            for (int j = 0; j < nums.size(); j++) {
                s += (nums[j] >> i) & 1;
            }
            cnt += s * (nums.size() - s);
        }
        return cnt;
    }
};

int main(void) {
    Solution s;
    vector<int> test = {4, 14, 2};
    cout << s.totalHammingDistance(test);
}