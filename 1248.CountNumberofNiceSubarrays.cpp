#include "defines.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> odds;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odds.push_back(i);
            }
        }
        int i = 0;
        int j = i + k - 1;
        int tmp = 0;
        while (j < odds.size()) {
            int beg = 0;
            int tai = 0;
            if (i == 0) {
                beg += odds[i] + 1;
            } else {
                beg += odds[i] - odds[i - 1];
            }
            if (j == odds.size() - 1) {
                tai += nums.size() - odds[j];
            } else {
                tai += odds[j + 1] - odds[j];
            }
            tmp += beg * tai;
            i++;
            j++;
        }
        return tmp;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = getVectorOfInt("[1,1,2,1,1]");
    cout << s.numberOfSubarrays(v, 3) << endl;
    v = getVectorOfInt("[2,4,6]");
    cout << s.numberOfSubarrays(v, 1) << endl;
    v = getVectorOfInt("[2,2,2,1,2,2,1,2,2,2]");
    cout << s.numberOfSubarrays(v, 2) << endl;
    v = getVectorOfInt("[2,1,2,2,1,2]");
    cout << s.numberOfSubarrays(v, 1) << endl;
    v = getVectorOfInt("[1,1,1,1,1,1]");
    cout << s.numberOfSubarrays(v, 1) << endl;
}