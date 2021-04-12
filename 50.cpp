#include "defines.h"

class Solution {
public:
    double myPow1(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double x1 = myPow(x, n >> 1);
        if (n&1) return x1 * x1 * x;
        else return x1 * x1;
    }
    double myPow(double x, int n) {
        if (n < 0) {
            double x1 = myPow1(x, -n);
            if (x1) return 1/x1;
            else return x1;
        }
        else
            return myPow1(x, n);
    }
};

int main(void) {
    Solution s;
    // for (int i = -100; i < 100; i++) {
    //     double a = pow(3, i);
    //     double b = s.myPow(3, i);
    //     double x = a - b;
    //     if (x < -0.00001 || x > 0.00001) 
    //         cout << i << "--" << a << " " << b << endl;
    // }
    // cout << "finish" << endl;
    cout << s.myPow(2, -2147483648);
    return 0;
}