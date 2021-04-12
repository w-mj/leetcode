#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
        int k = 1;
        while (candies > 0) {
            if (k > candies)
                k = candies;
            ans[i] += k;
            i++;
            candies -= k;
            k++;
            if (i == num_people)
                i = 0;
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif