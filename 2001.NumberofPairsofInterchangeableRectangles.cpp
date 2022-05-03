#include "defines.h"
#include <utility>


int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> cnt;
        for (auto& rec: rectangles) {
            int w = rec[0];
            int h = rec[1];
            int g = gcd(w, h);
            pair<int, int> key = make_pair(w / g, h / g);
            cnt[key] += 1;
        }

        long long ans = 0;
        for (auto& e: cnt) {
            long long n = e.second;
            if (n & 1) {
                ans += n * ((n - 1) >> 1);
            } else {
                ans += (n >> 1) * (n - 1);
            }
        }
        return ans;
    }
};