#include "defines.h"


class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            if (v1[1] < v2[1]) {
                return true;
            }
            if (v1[1] == v2[1]) {
                return v1[0] < v2[0];
            }
            return false;
        });

        int limit=intervals[0][1];  
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<limit) 
                ans++;
            else
                limit=intervals[i][1];   
        }
        return ans;
    }
};


int main() {
    auto vv = getVectorOfVectorOfInt("[[1,2],[2,3],[3,4],[1,3]]");
    Solution s;
    // cout << s.eraseOverlapIntervals(vv) << endl;
    vv = getVectorOfVectorOfInt("[[1,2],[1,2],[1,2]]");
    cout << s.eraseOverlapIntervals(vv) << endl;
}