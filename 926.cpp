#include "defines.h"

class Solution {
   public:
    int minFlipsMonoIncr(string S) {
        int to_0[S.size() + 1];
        int to_1[S.size() + 1];
        to_0[0] = 0;
        to_1[S.size()] = 0;
        for (int i = 1; i <= S.size(); i++)
            to_0[i] = to_0[i - 1] + (S[i - 1] == '1');
        for (int i = S.size() - 1; i >= 0; i--)
            to_1[i] = to_1[i + 1] + (S[i] == '0');
        int min_f = S.size() + 10;
        for (int i = 0; i <= S.size(); i++) {
            min_f = min(min_f, to_0[i] + to_1[i]);
        }
        return min_f;
    }
};

int main(void) {
    Solution s;
   cout << s.minFlipsMonoIncr("00110") << endl;
    cout << s.minFlipsMonoIncr("010110") << endl;
    cout << s.minFlipsMonoIncr("00011000") << endl;
    cout << s.minFlipsMonoIncr("1") << endl;

    return 0;
}