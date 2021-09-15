#include "defines.h"


class Solution {
public:
    int longestPalindrome(string s) {
        int arr[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[s[i]] ++;
        }
        int cnt = 0;
        for (int i = 0; i < 256; i++) {
            cnt += arr[i] & (~1);
        }
        if (cnt < s.size()) {
            cnt += 1;
        }
        return cnt;
    }
};

int main(void) {
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
    cout << s.longestPalindrome("a") << endl;
    cout << s.longestPalindrome("bb") << endl;
}