#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    map<pair<string, int>, int> memo;
    int kSimilarity(string A, string B, int i, int k) {
        if (A == B) {
            memo.insert(make_pair(make_pair(A, i), k));
            return k;
        }
        int mink = INT_MAX;
        for (int j = i + 1; j < A.size(); j++) {
            // cout << i<< " " << j << endl;
            int t=0;
            if (memo.find(make_pair(A, i + 1)) != memo.end()) {
                t = memo[make_pair(A, i + 1)];
            } else {
                if (A[i] == A[j]){
                    t = kSimilarity(A, B, i + 1, k);
                } else {
                    swap(A[i], A[j]);
                    t = kSimilarity(A, B, i + 1, k + 1);
                    swap(A[i], A[j]);
                }
                // memo.insert(make_pair(make_pair(A, i + 1), t));
            }
            mink = min(mink, t);
        }
        return mink;
    }
    int kSimilarity(string A, string B) {
        if (A == B)
            return 0;
        memo.clear();
        string a, b;
        for (size_t i =0 ; i < A.size(); i++) {
            if (A[i] != B[i]) {
                a.push_back(A[i]);
                b.push_back(B[i]);
            }
        }
        return kSimilarity(a, b, 0, 0);
    }
};

int main(void) {
    Solution s;
    cout << s.kSimilarity("ab", "ba") << endl;
    cout << s.kSimilarity("abc", "bca") << endl;
    cout << s.kSimilarity("abac", "baca") << endl;
    cout << s.kSimilarity("aabc", "abca") << endl;
    cout << s.kSimilarity("abccaacceecdeea", "bcaacceeccdeaae") << endl;

    return 0;
}

#endif