#include "defines.h"

class Solution {
public:
    int tupleSameProduct(const vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                m[nums[i] * nums[j]]++;
            }
        }
        int cnt = 0;
        for (auto x: m) {
            cnt += 4 * x.second * (x.second - 1);
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.tupleSameProduct({2, 3, 4, 6}) << endl;
    cout << s.tupleSameProduct({1, 2, 4, 5, 10}) << endl;
    cout << s.tupleSameProduct({2, 3, 4, 6, 8, 12}) << endl;
    cout << s.tupleSameProduct({2, 3, 5, 7}) << endl;
}