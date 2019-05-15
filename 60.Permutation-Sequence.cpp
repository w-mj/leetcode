#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    char getK(string& s, int k) {
        int i = 0;
        while (s[i] == 'a')
            i++;
        while (k) {
            if (s[i] != 'a')
                k--;
            i++;
        }
        while (s[i] == 'a')
            i++;
        char c = s[i];
        s[i] = 'a';
        return c;
    }
    string getPermutation(int n, int k) {
        k --;
        string num = "123456789";
        int factorials[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        string result(n, '0');
        int m = n - 1;
        for (int i = 0; i < n; i++) {
            result[i] = getK(num, k / factorials[m]);
            // if (k >= factorials[m])
            k = k % factorials[m];
            m -= 1;
        } 
        return result;
    }
};

int main(void) {
    Solution s;
    cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(4, 9) << endl;
    cout << s.getPermutation(8, 31492) << endl;

    // for (int i = 1; i <= 15; i++)
    //     cout << s.getPermutation(9, i) << endl;

    return 0;
}

#endif