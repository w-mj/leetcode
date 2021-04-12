#include "defines.h"

class Solution {
public:
    bool equal(const vector<int> &a, const vector<int> &b, const vector<int>&c) {
        int ia = 0;
        int ib = 0;
        int ic = 0;
        while (a[ia] == 0) ia++;
        while (b[ib] == 0) ib++;
        while (c[ic] == 0) ic++;
        if ((a.size() - ia != b.size() - ib) || (b.size() - ib != c.size() - ic))
            return false;
        while (ia < a.size()) {
            if ((a[ia] != b[ib]) || (b[ib] != c[ic])) return false;
            else {
                ia++;
                ib++;
                ic++;
            }
        }
        return true;
    }
    vector<int> threeEqualParts(vector<int>& A) {
        for ()
    }
};

int main(void) {
    Solution s;

    return 0;
}