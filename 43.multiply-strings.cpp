/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (29.93%)
 * Total Accepted:    186K
 * Total Submissions: 619.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

#ifdef LOCAL_DEBUG
#include "defines.h"
#endif

class Solution {
public:
    void add(string& s1, const string& s2, int off=0) {
        //cout << "add: " << s1 << " + " << s2;
        if (off + s2.size() > s1.size())
            s1.insert(s1.begin(), off + s2.size() - s1.size(), '0');
        int i = s1.size() - 1 - off;
        int j = s2.size() - 1;
        int t, carry = 0;
        while (i >= 0 && j >= 0) {
            t = s1[i] - '0' + s2[j] - '0' + carry;
            carry = t / 10;
            t = t % 10;
            s1[i] = t + '0';
            i--;
            j--;
        }
        if (carry) {
            while (i >= 0 && s1[i] == '9')
                s1[i--] = '0';
            if (i == -1)
                s1.insert(s1.begin(), '1');
            else 
                s1[i] += 1;
        }
        //cout << " = " << s1 << endl;
    }
    string multiply(string s1, char c) {
        //cout << "multiply " << s1 << " * " << c;
        int i = s1.size() - 1;
        int t, carry = 0;
        int n = c - '0';
        while (i >= 0) {
            t = (s1[i] - '0') * n + carry;
            carry = t / 10;
            t = t % 10;
            s1[i] = t + '0';
            i--;
        }
        if (carry)
            s1.insert(s1.begin(), carry + '0');
        //cout << " = " << s1 << endl;
        return s1;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string result = "0";
        int n = num2.size();
        int i = n - 1;
        while (i >= 0) {
            add(result, multiply(num1, num2[i]), n - 1 - i);
            i--;
        }
        return result;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    srand(time(nullptr));
    for (int i = 0; i < 1000; i++) {
        ll n1 = rand();
        ll n2 = rand();
        string tar = to_string(n1 * n2);
        string res = s.multiply(to_string(n1), to_string(n2));
        if (tar != res) {
            cout << n1 << " * " << n2 << " should be " << tar << ", but got " << res << endl;
        }
    }
    cout << s.multiply("2", "3") << endl;
    cout << s.multiply("123", "456") << endl;

    return 0;
}

#endif

