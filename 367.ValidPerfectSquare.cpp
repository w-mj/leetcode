#include "defines.h"


class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i = 0;
        long long j = 46341;
        while (i <= j) {
            long long mid = (i + j) / 2;
            long long p = mid * mid;
            if (p == num) {
                return true;
            } else if (p < num) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return false;
    }
};

int main(void) {
    long long x = 0;
    long long p;
    unsigned long long end = INT32_MAX;
    cout << "int arr[] = {";
    do {
        p = x * x;
        // cout << x << "*" << x << "=" << p << "\n";
        x++;
    } while (p < INT32_MAX);
    cout << "}\n" << endl;
    return 0;
}