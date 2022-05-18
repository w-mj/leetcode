#include "defines.h"

constexpr int mod = (int)1e9+7;
class Solution {
public:
    long long calsum(long long n) {
        if (n & 1) {
            return (n * ((n + 1) >> 1)) % mod;
        } else {
            return ((n >> 1) * (n + 1)) % mod;
        }
    }
    int countHomogenous(string s) {
        int start = 0;
        long long ans = 0;
        while (start < s.size()) {
            int i = start + 1;
            for (; i < s.size(); i++) {
                if (s[i] != s[start]) {
                    ans += calsum(i - start);
                    ans %= mod;
                    start = i;
                    break;
                }
            }
            if (i == s.size()) {
                break;
            }
        }
        ans += calsum(s.size() - start);
        ans %= mod;
        return ans;
    }
};