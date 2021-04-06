#include "defines.h"

// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int D) {
//         int s = 0;
//         int e = weights.size();
//         int d = D - 1;

//         int dp[weights.size() + 10][D + 10];

//         dp[e][0] = 0;
//         for (int i = e - 1; i >= 0; i--) {
//             dp[i][0] = dp[i + 1][0] + weights[i];
//         }

//         for (int d = 1; d < D; d++) {
//             for (int s = e - d; s >= 0; s--) {
//                 int maxi = INT_MAX;
//                 int sumn = weights[s];
//                 for (int t = s + 1; t <= e - d; t++ ) {
//                     maxi = min(maxi, max(sumn, dp[t][d - 1]));
//                     sumn += weights[t];
//                 } 
//                 dp[s][d] = maxi;
//             }
//         }
//         return dp[0][D - 1];
//     }
// };


class Solution {
public:
    bool isPossible(vector<int>& weights, int D,int capacity){
        int count=0;
        int i=0;
        int curr=0;
        while(i<weights.size()){
            curr+=weights[i];
            if(curr>capacity){
                curr=weights[i];
                count++;
            }
            i++;
        }
        return (count+1<=D);
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid=low+(high-low)/2;
            if(isPossible(weights,D,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

int main(void) {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << s.shipWithinDays(v, 5) << endl;
}
