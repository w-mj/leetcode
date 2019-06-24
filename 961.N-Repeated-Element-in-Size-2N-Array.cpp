#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int cnt[10010] = {0};
        for (auto x: A)
            cnt[x]++;
        for (int i = 0; i < 10010; i++) {
            if (cnt[i] == (A.size() >> 1))
                return i;
        }
        return -1;
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif