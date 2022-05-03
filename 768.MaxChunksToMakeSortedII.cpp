#include "defines.h"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int maxLeft = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxLeft = max(maxLeft, arr[i]);
            int maxTemp = maxLeft;
            int j;
            for (j = i + 1; j < arr.size(); j++) {
                if (maxLeft > arr[j]) {
                    break;
                }
                maxTemp = max(maxTemp, arr[j]);
            }
            if (j == arr.size()) {
                ans += 1;
                maxLeft = 0;
            } else {
                i = j - 1;
                maxLeft = maxTemp;
            }
        }
        return ans;
    }
};