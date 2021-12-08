#include "defines.h"

class Solution {
public:
    int str2int(const string& s) {
        int ans = 0;
        for (char c : s) {
            ans = ans * 10 + (c - 'a');;
        }
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return str2int(firstWord) + str2int(secondWord) == str2int(targetWord);
    }
};