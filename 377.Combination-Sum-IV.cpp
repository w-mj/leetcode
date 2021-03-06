#ifdef LOCAL_DEBUG
#include "defines.h"
//[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]
//999
//[3, 33, 333]
//10000
//[3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]
//10


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        bool could[target + 1] = {0};
        int dp[target + 1] = {0};
        for (auto x: nums) {
            if (x <= target) {
                could[x] = true;
            }
        }
        int n = target + 1;
        for (int i = 0; i < n; i++) {
            if (could[i]) {
                for (int j = i; j < n && i + j < n; j++) {
                    if (could[j])
                        could[i + j] = true;
                }
            }
        }

        if (!could[target]) {
            return 0;
        }
        could[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (target - nums[i] >= 0 && could[target - nums[i]]) {
                dp[nums[i]] = 1;
            }
        }
        // for (auto x: nums)
        //     cout << x<< ' ';
        // cout << endl;
        // cout << nums.size();
        
        // for (int i = 0; i <= target; i++) {
        //     cout << i << ":" << dp[i] << endl;
        // }

        for (int i = 1; i <= target; i++) {
            for (auto x: nums) {
                if (i - x > 0 && could[target - i])
                    dp[i] += dp[i - x];
            }
        }
        return dp[target];
    }
};

int main(void) {
    Solution s;
    vector<int> v = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    vector<int> v2 = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    // cout << s.combinationSum411(v, 10000) << endl;
    cout << s.combinationSum4(v2, 10) << endl;

    return 0;
}

#endif