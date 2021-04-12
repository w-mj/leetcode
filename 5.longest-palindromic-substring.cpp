

#include "defines.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int e = s.size();
        int dp[1010][1010] = {0};
        for (int i = 0; i < e - 1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                dp[i][i+1] = 1;
            }
        }
        dp[e-1][e-1] = 1;
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < e; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        int window = 3;
        for (; window <= e; window++) {
            for (int i = 0; i <= e - window; i++) {
                int j = i + window - 1;
                if (dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        while (window > 0) {
            for (int i = 0; i <= e - window; i++) {
                int j = i + window - 1;
                if (dp[i][j])
                    return s.substr(i, window);
            }
            window--;
        }
        return s.substr(0, 1);
    }
};


int main(void) {
    Solution s;
    cout << s.longestPalindrome("bb") << endl;
    return 0;
}