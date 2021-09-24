#include "defines.h"

class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int mod = (int)1e9 + 7;        
        for (int i = 1; i <= n; i++) {
            ans = ans * (i * (2 * i - 1));
            ans = ans % mod;
        }
        return (int)ans;
    }
};

int main() {
    Solution s;
    cout << s.countOrders(1) << endl;
    cout << s.countOrders(2) << endl;
    cout << s.countOrders(3) << endl;
    cout << s.countOrders(500) << endl;
}