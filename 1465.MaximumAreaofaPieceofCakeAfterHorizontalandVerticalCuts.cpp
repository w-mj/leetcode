#include "defines.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxW = 0;
        int lastW = 0;
        for (int h: horizontalCuts) {
            maxW = max(maxW, h - lastW);
            lastW = h;
        }
        int maxH = 0;
        int lastH = 0;
        for (int w: verticalCuts) {
            maxH = max(maxH, w - lastH);
            lastH = w;
        }

        return (((long long) maxW) * maxH) % (int (1e9+7));
    }
};