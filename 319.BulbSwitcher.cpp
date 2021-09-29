#include "defines.h"

class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.bulbSwitch(3) << endl;
    cout << s.bulbSwitch(4) << endl;
    cout << s.bulbSwitch(10) << endl;
    cout << s.bulbSwitch(11) << endl;
}