#include "defines.h"


int gcd(int a,int b){
    if (a < b) {
        swap(a, b);
    }
	while(a % b){
		int tmp = a;
		a = b;
		b = tmp % a;
	}
	return b; 
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) {
            k = k % n;
        }

        if (k == 0) {
            return;
        }

        int g = gcd(n, k);
        int step = g;

        for (int i = 0; i < step; i++) {
            int t1 = nums[i], t2;
            int t = i;
            do {
                t = (t + k) % n;
                if (t == i) {
                    break;
                }
                t2 = nums[t];
                nums[t] = t1;
                t1 = t2;
            } while (true);
            nums[i] = t1;
        }
    }
};