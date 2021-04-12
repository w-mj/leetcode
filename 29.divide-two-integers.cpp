/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.06%)
 * Total Accepted:    181.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int d1 = (unsigned)dividend;
        unsigned int d2 = (unsigned)divisor;
        if (d1 == 0)
            return 0;
        if (d2 == 1)
            return d1;
        int cnt = 0;
        int result = 0;
        bool negative = ((d1 ^ d2) & 0x80000000) > 0;

        d1 = (d1 & 0x80000000)? (~d1) + 1: d1;
        d2 = (d2 & 0x80000000) ? (~d2) + 1 : d2;

        while ((d2 & 0x80000000) == 0) {
            cnt += 1;
            d2 <<= 1;
        }
        while (true) {
            if (d1 >= d2) {
                d1 = d1 - d2;
                result = result | 0x01;
            }
            d2 = d2 >> 1;
            cnt -= 1;
            if (cnt < 0)
                break;
            result <<= 1;
        }
        return result & 0x80000000 ? 2147483647: negative ? -result : result;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    cout << s.divide(-2147483648, -1) << endl;
    cout << s.divide(-2147483648, 1) << endl;

    cout << s.divide(-1, 1) << endl;
    cout << s.divide(10, 3) << endl;
    cout << s.divide(7, -3) << endl;

    return 0;
}

#endif

