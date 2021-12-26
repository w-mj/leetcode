#include "defines.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = *max_element(piles.begin(), piles.end());

        while (i < j) {
            int m = (i + j) / 2;
            int k = 0;
            for (int p: piles) {
                k += p / m + ((p % m) > 0);
            }
            if (k > h) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> v = {3, 6, 7, 11};
    int h = 8;
    cout << s.minEatingSpeed(v, h) << endl;
}