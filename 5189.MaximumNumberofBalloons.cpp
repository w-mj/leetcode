#include "defines.h"


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int chars[26] = {0};
        for (auto c: text) {
            ++chars[c - 'a'];
        }
        int b = chars['b' - 'a'];
        int a = chars['a' - 'a'];
        int l = chars['l' - 'a'] / 2;
        int o = chars['o' - 'a'] / 2;
        int n = chars['n' - 'a'];
        return min(b, min(a, min(l, min(o, n))));
    }
};
int main(void) {
    Solution s;
    
}