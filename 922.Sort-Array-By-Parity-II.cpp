/*
Given an array A of non-negative integers, half of the integers in A are odd, 
and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Note:
    2 <= A.length <= 20000
    A.length % 2 == 0
    0 <= A[i] <= 1000
*/


#ifdef LOCAL_DEBUG
#include "defines.h"

#define odd(a) ((a)&1)
#define even(a) (!odd(a))
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (even(i) && odd(A[i])) {
                int j = i + 1;
                while (odd(A[j])) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
            if (odd(i) && even(A[i])) {
                int j = i + 1;
                while (even(A[j])) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};
int main(void) {
    Solution s;
    vector<int> A = {4,2,5,7};
    s.sortArrayByParityII(A);
    return 0;
}

#endif