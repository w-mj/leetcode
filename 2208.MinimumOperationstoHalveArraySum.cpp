#include "defines.h"
#include <numeric>
#include <queue>

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> qu;
        double sum = 0;
        for (int n: nums) {
            qu.push(n);
            sum += n;
        }

        int ans = 0;
        double flag = sum / 2;
        while (sum > flag) {
            double n = qu.top();
            qu.pop();
            n = n / 2;
            sum -= n;
            ans += 1;
            qu.push(n);
        }
        return ans;
    }
};