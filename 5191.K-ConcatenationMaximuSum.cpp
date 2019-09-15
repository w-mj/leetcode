#include "defines.h"

class Solution {
public:
    int a = 0;
    int kk = 0;
    vector<int>* parr = nullptr;
    bool finish = false;
    int getNext() {
        int ans = (*parr)[a];
        a = a + 1;
        if (a == (*parr).size()) {
            a = 0;
            kk--;
            if (kk == 0)
                finish = true;
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        kk = k;
        parr = &arr;
        finish = false;
        int sum = 0;
        int minf = 0;
        for (int i : arr) {
            sum += i;
        }
        sum = sum % int(1e9+7);
        if (sum > 0) {
            int minl = 0;
            int ss =0;
            for (size_t i = 0; i < arr.size(); i++) {
                ss += arr[i];
                minf = min(minf, ss);
            }
            ss = 0;
            for (size_t i = arr.size() - 1;  i >= 0; i--) {
                ss += arr[i];
                minl = min(minl, ss);
            }
            long long ssum = sum;
            long long res = (ssum * k);
            return res  % int(1e9+7) - minl - minf;
        }
        if (sum <= 0)
            kk = 2;

        int maxn = 0;
        int t  = 0;
        int last_update = 0;
        while (!finish) {
            int n = getNext();
            t = t + n;
            if (t < 0)
                t = 0;
            if (t > maxn) {
                last_update = a;
                maxn = t;
            }
        }
        return maxn;
    }
};