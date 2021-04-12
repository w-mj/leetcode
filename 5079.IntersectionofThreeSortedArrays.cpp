#include "defines.h"
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> cnt(2001, 0);
        for (auto x: arr1) cnt[x]++;
        for (auto x: arr2) cnt[x]++;
        for (auto x: arr3) cnt[x]++;
        vector<int> ans;
        for (size_t i = 0; i < 2000; i++)
            if (cnt[i] == 3)
                ans.push_back(i);
        return ans;
    }
};