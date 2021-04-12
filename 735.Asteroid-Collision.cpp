#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    // 正数向右，负数向左
    vector<int> asteroidCollision(vector<int>& asteroids) {
        size_t i = 0;
        vector<int> ans;
        for (; i < asteroids.size();) {
            if (ans.size() == 0) {
                ans.push_back(asteroids[i]);
                i++;
            } else if ((ans.back() > 0 && asteroids[i] < 0)) {
                if (abs(ans.back()) < abs(asteroids[i])) {
                    ans.pop_back();
                } else if (abs(ans.back()) == abs(asteroids[i])) {
                    ans.pop_back();
                    i++;
                } else {
                    i++;
                }
            } else {
                ans.push_back(asteroids[i]);
                i++;
            }
        }
        return ans;
    }
};


int main(void) {
    Solution s;
    return 0;
}

#endif