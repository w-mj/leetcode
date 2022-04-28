#include "defines.h"
#include <memory>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int arr[1020] = {};
        int maxc = 0;
        for (int i: citations) {
            arr[i] += 1;
            maxc = max(maxc, i);
        }

        for (int i = maxc; i > 0; i--) {
            if (arr[i] >= i) {
                return i;
            }
            arr[i - 1] += arr[i];
        }
        return 0;
    }
};


int main(void) {
    Solution s;
    auto v = getVectorOfInt("[2,2,2,2]");
    cout << s.hIndex(v) << endl;
}