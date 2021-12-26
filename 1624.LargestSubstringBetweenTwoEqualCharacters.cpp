#include "defines.h"

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int cnt[256] = {0};
        for (int i = 0; i < 256; i++) {
            cnt[i] = -1;
        }
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (cnt[s[i]] != -1) {
                // cout << s[i] << " " << cnt[s[i]] << " " << i << endl;
                ans = max(i - cnt[s[i]] - 1, ans);
            } else {
                cnt[s[i]] = i;
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    // cout << s.maxLengthBetweenEqualCharacters("aa") << endl;
    // cout << s.maxLengthBetweenEqualCharacters("dabcda") << endl;
    // cout << s.maxLengthBetweenEqualCharacters("cbzxy") << endl;
    cout << s.maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv") << endl;
}