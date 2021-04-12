#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        int hs[][10] = {{1, 0}, {4, 1, 2, 4, 8}, {5, 3, 5, 6, 9, 10, 12}, {2, 7, 11, 13, 14}, {0, 15}};
        int ms[][21] = {
            {1,0},
            {6,1,2,4,8,16,32},
            {15,3,5,6,9,10,12,17,18,20,24,33,34,36,40,48},
            {20,7,11,13,14,19,21,22,25,26,28,35,37,38,41,42,44,49,50,52,56},
            {14,15,23,27,29,30,39,43,45,46,51,53,54,57,58,60},
            {4,31,47,55,59,61,62},
            {0,63}
        };
        for (int h = 0; h <= min(num, 4); h++) {
            int m = num - h;
            if (m > 6)
                continue;
            for (int i = 1; i <= hs[h][0]; i++) {
                for (int j = 1; j <= ms[m][0]; j++) {
                    stringstream ss;
                    ss << hs[h][i];
                    if (ms[m][j]<10)
                        ss << ":0";
                    else
                        ss << ":";
                    ss << ms[m][j];
                    ans.emplace_back(ss.str());
                }
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
