#include "defines.h"
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int k = 9;
            for (int j = 9; j > 9 - i; j--) {
                k *= j;
            }
            ans += k;
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    std::cout << s.countNumbersWithUniqueDigits(4);
}