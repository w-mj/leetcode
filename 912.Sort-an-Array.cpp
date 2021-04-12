#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    void sort(vector<int>& nums, int s, int e)
    {
        if (s >= e)
            return;
        int b = s, d = e;
        int p = nums[s];
        while (s < e) {
            while (s < e && nums[e] >= p)
                e--;
            if (s < e)
                nums[s++] = nums[e];
            while (s < e && nums[s] <= p)
                s++;
            if (s < e)
                nums[e--] = nums[s];
        }
        nums[s] = p;
        sort(nums, b, s - 1);
        sort(nums, s + 1, d);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(void) {
    Solution s;
    vector<int> v1, v2;
    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        int n = rand();
        v1.push_back(n);
        v2.push_back(n);
    }
    sort(v1.begin(), v1.end());
    s.sortArray(v2);
    cout << (v1 == v2) << endl;
    return 0;
}

#endif