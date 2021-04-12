#ifdef LOCAL_DEBUG
#include "defines.h"

#define ll long long
#define mkp make_pair
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> off(n + 1, 0);
        vector<int> ans(n, 0);
        for (auto &x: bookings) {
            off[x[0] - 1] += x[2];
            off[x[1]] += -x[2];
        }
        // printList(off);
        int res = 0;
        for (size_t i = 0; i < n; i++) {
            res += off[i];
            ans[i] = res;
        }
        return ans;
    }
};

int main(void) {
    vector<vector<int>> a = 
        {{1,2,10},{2,3,20},{2,5,25}};
    vector<vector<int>> b = 
        {{2, 2, 50},{1, 1, 35},{3, 3, 40},{1, 4, 50}};
    Solution s;
    printList(s.corpFlightBookings(a, 5));
    printList(s.corpFlightBookings(b, 4));

    return 0;
}

#endif