#include "defines.h"

class Solution {
public:
    int f1(vector<int>& A, int K) {
        int table[20010] = {0};
        int dis = 0;
        int ans = 0;
        int sz = A.size();
        int j = 0;
        int i = 0;
        while(j < sz) {
            int k = A[j];
            if (table[k] == 0) {
                dis ++;
            }
            table[k]++;
            if (dis <= K) {
                ans += j - i + 1;
                j++;
            }
            if (dis > K) {
                while (dis > K) {
                    table[A[i]]--;
                    if (table[A[i]] == 0) {
                        dis--;
                    }
                    i++;
                }
                ans += j - i + 1;
                j++;
            }
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return f1(A, K) - f1(A, K - 1);
    }
};

int main(void) {
    Solution s;
    vector<int> a = {1, 2, 1, 2, 3};
    cout << s.subarraysWithKDistinct(a, 2) << endl;
}