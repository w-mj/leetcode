#include "defines.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hash[32] = {0};
        for (auto c: chars) {
            hash[c - 'a'] += 1;
        }
        int ans = 0;
        int stat[32] = {0};
        for (auto &w: words) {
            memcpy(stat, hash, 32 * sizeof(int));
            for (auto c: w) {
                if (stat[c - 'a'] > 0)
                    stat[c - 'a'] -= 1;
                else {
                    goto out;
                }
            }
            ans += w.size();
            out:
            if(true)
            {}
        }
        return ans;
    }
};

int main(void) {
    vector<string> i1 = {"cat","bt","hat","tree"};
    vector<string> i2 = {"hello","world","leetcode"};
    Solution s;
    cout << s.countCharacters(i1, "atach") << endl;
    cout << s.countCharacters(i2, "welldonehoneyr") << endl;
    return 0;
}