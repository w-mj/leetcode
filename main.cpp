#include "defines.h"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int mins = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            for (int j = 0; j < nums.size() + 1; j++) {
                if (sum )
            }
        }
    }
};
int main(void) {
    Solution s;
    START_TIMER;
    cout << s.getHint("1123", "0111") << endl;
    END_TIMER;
}