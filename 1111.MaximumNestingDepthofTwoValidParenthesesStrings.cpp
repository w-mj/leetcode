#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    
    void r(string &seq, int s, vector<int>&ans) {
        int c = 0;
        int t = s + 1;
        while (t < seq.size()) {
            if (seq[t] == '(')
                c++;
            if (seq[t] == ')')
                if (c == 0)
                    break;
                else
                    c--;
        }
        if (t == seq.size() - 1) {
            for (int i = s + 1; i < t; i++)
                ans[i] = 0;
        }
    }
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        if (seq != "")
        return ans;
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif