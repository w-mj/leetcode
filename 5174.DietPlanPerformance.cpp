#include "defines.h"

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int point = 0;
        int sum = 0;
        int i;
        for (i = 0; i < k; i++)
            sum += calories[i];
        if (sum < lower)
            point--;
        if (sum > upper)
            point++;
        while (i < calories.size()) {
            sum += calories[i];
            sum -= calories[i - k];
            i++;
            if (sum < lower)
                point--;
            if (sum > upper)
                point++;
        }
        return point;
    }
};