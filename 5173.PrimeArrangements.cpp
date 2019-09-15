#include "defines.h"

class Solution {
public:
    long long A(int m, int n) {
        long long r = 1;
        while (n--) {
            r = r * m;
            --m;
            r = r % (int(1e9 + 7));
        }
        return r % (int(1e9 + 7));
    }
    long long A(int n) {
        return A(n, n);
    }
    int numPrimeArrangements(int n) {
        long long x;
        vector<int> primes = {0,0,1,2,2,3,3,4,4,4,4,5,5,6,6,6,6,7,7,8,8,8,8,9,9,9,9,9,9,10,10,11,11,11,11,11,11,12,12,12,12,13,13,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,16,17,17,18,18,18,18,18,18,19,19,19,19,20,20,21,21,21,21,21,21,22,22,22,22,23,23,23,23,23,23,24,24,24,24,24,24,24,24,25,25,25,25};
        
        return (A(primes[n]) * A(n - primes[n]) )% int(1e9 + 7);
    }   
};

int main(void) {
    Solution s;
    cout << s.numPrimeArrangements(1) << endl;
    cout << s.numPrimeArrangements(2) << endl;
    cout << s.numPrimeArrangements(5) << endl;
    cout << s.numPrimeArrangements(100) << endl;

}