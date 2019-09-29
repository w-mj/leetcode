#include "defines.h"



class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int max_n = 1000000;
        for (size_t i = 0; i < arr.size() - 1; i++) {
            max_n = min(max_n, abs(arr[i + 1] - arr[i]));
        }   
        vector<vector<int>> ans;
        for (size_t i = 0; i < arr.size() - 1; i++) {
            if (abs(arr[i + 1] - arr[i]) == max_n) {
                vector<int> a {min(arr[i], arr[i + 1]), max(arr[i], arr[i + 1])};
                ans.emplace_back(a);
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};