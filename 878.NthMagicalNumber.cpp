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

int get_lcm(int a, int b) {
    return a * b / gcd(a, b);
}

const int mod = 1e9+7;
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = get_lcm(a, b);
        int group_cnt = (lcm / a - 1) + (lcm / b - 1) + 1;
        int group_num = n / group_cnt;
        int in_group = n % group_cnt;

        long long group_start = (long long)group_num * lcm % mod;
        if (in_group == 0) {
            return group_start;
        }

        int t_a = a, t_b = b;
        for (int i = 0; i < in_group - 1; i++) {
            if (t_a <= t_b) {
                t_a += a;
            } else {
                t_b += b;
            }
        }
        return (group_start + min(t_a, t_b)) % mod;
    }
};

int main() {
    Solution s;
    cout << s.nthMagicalNumber(1, 2, 3) << endl;
    cout << s.nthMagicalNumber(4, 2, 3) << endl;
}