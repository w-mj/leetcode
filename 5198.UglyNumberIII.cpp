#include "defines.h"

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int ia = 1;
        int ib = 1;
        int ic = 1;
        int ta = a;
        int tb = b;
        int tc = c;
        int ans = a;
        for (int i = 1; i <= n; i++) {
            int t = min(min(ta, tb), tc);
            if (i == n) {
                ans = t;
                break;
            }
            if (t == ta) {
                ia++;
                ta = ia * a;
            }
            if (t == tb) {
                ib++;
                tb = ib * b;
            }
            if (t == tc) {
                ic++;
                tc = ic * c;
            }
        } 
        return ans;
    }
};

int main(void) {
    Solution s;
    cout << s.nthUglyNumber(3, 2, 3, 5) << " == 4" << endl;
    cout << s.nthUglyNumber(4, 2, 3, 4) << " == 6" << endl;
    cout << s.nthUglyNumber(5, 2, 11, 13) << " == 10" << endl;
    cout << s.nthUglyNumber(1000000000, 2, 217983653, 336916467) << " == 1999999984" << endl;

}
/*
class Solution {
public:
    
    long long gcd(long long x, long long y) {
        long long t;
        while (x%y != 0) {
            t = x % y;
            x = y;
            y = t;
        }
        return y;
    }
    
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
    
    bool check(long long x, long long a, long long b, long long c, int n) {
        long long cnt = x / a + x / b + x / c
                      - x / lcm(a,b) - x / lcm(b,c) - x / lcm(a,c)
                      + x / lcm(lcm(a,b),c);
        /*
        printf("%lld, %lld, %lld; - %lld, %lld, %lld; + %lld\n",
                        x / a, x / b, x / c,
                        x / lcm(a,b), x / lcm(b,c), x / lcm(a,c),
                        x / lcm(lcm(a,b),c));
        printf("x=%d: %d ? %d\n", (int)x, (int)cnt, (int)n);
        //*/
        return cnt >= n;
    }
    
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long long B = 1, E = 2147483647;
        while (E > B + 1) {
            long long M = (B+E)/2;
            if (check(M, a, b, c, n)) {
                E = M;
            } else{
                B = M;
            }
        }
        return E;
    }
};
*/