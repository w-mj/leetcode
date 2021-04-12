#include "defines.h"

class Solution {
public:
    bool check(const vector<int>& piles, int H, int k) {
        int sum = 0;
        for (int a: piles)
            sum += (a / k + ((a % k) != 0));
        return sum <= H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        if (piles.size() == 1) {
            return piles[0] / H + (piles[0] % H != 0);
        }
        sort(piles.begin(), piles.end());
        int K_i = piles.size() - 1;
        bool check_result;
        int low = 0, top = piles.size() - 1;
        map<int, bool> success;
        if (!check(piles, H, piles[0])) {
            while(low <= top) {
                int test = (low + top) / 2;
                bool result = check(piles, H, piles[test]);
                if (result) {
                    if (success.find(test - 1) != success.end() && success[test - 1] == false) {
                        K_i = test;
                        break;
                    }
                    success.insert(make_pair(test, true));
                    top = test;
                } else {
                    if (success.find(test + 1) != success.end() && success[test + 1] == true) {
                        K_i = test + 1;
                    }
                    success.insert(make_pair(test, false));
                    low = test + 1;
                }
            }
            low = piles[K_i - 1];
            top = piles[K_i];
        } else {
            low = 0;
            top = piles[0];
        }
        
        while(low <= top) {
            int test = (low + top) / 2;
            bool result = check(piles, H, test);
            if (result) {
                if (success.find(test - 1) != success.end() && success[test - 1] == false)
                    return test;
                success.insert(make_pair(test, true));
                top = test;
            } else {
                if (success.find(test + 1) != success.end() && success[test + 1] == true) 
                    return test + 1;
                success.insert(make_pair(test, false));
                low = test + 1;
            }
        }
        return 1;
    }
};

int main(void) {
    vector<int> v = {30,11,23,4,20};
    Solution s;
    cout << s.minEatingSpeed(v, 5);
    return 0;
}