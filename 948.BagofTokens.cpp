#include "defines.h"


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());       
        int i = 0, j = tokens.size();
        int ans = 0;
        int score = 0;
        while (i < j) {
            if (tokens[i] <= power) {
                score += 1;
                power -= tokens[i];
                i++;
                ans = max(ans, score);
            } else if (score > 0) {
                j -= 1;
                power += tokens[j];
                score -= 1;
            } else {
                break;
            }
        }
        return ans;
    }
};