#include "defines.h"

class Solution {
public:
    bool isPalindrome(string s, int i=0, int j=-1) {
        if (j == -1) j = s.size();
        j -= 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else 
                return false;
        }
        return true;
    }
    int longestPalindromeSubseq(string s) {
        int dp[s.size() + 1];
        memset(dp, 0, s.size() + 1);

    }
};

int main(void) {
    Solution s;

    return 0;
}