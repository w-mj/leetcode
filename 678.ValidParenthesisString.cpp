#include "defines.h"


// class Solution {
// public:
//     bool checkValidString(string s) {
//         if (s.empty()) {
//             return true;
//         }

//         vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '*') {
//                 dp[i][i] = true;
//             }
//             if (i < s.size() - 1 && (s[i] == '(' || s[i] == '*') && (s[i + 1] == ')' || s[i + 1] == '*')) {
//                 dp[i][i+1] = true;
//             }
//         }

//         for (int size = 2; size < s.size(); size++) {
//             for (int i = 0; i < s.size() - size; i++) {
//                 int j = i + size;
//                 if (s[i] == '*' && dp[i + 1][j]) {
//                     dp[i][j] = true;
//                 } else if (s[i] == '(' || s[i] == '*') {
//                     for (int k = i + 1; k <= j; k++) {
//                         if ((s[k] == ')' || s[k] == '*') && (k == i + 1 || dp[i+1][k-1] == true) && (k == j || dp[k+1][j] == true)) {
//                             dp[i][j] = true;
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[0][s.size() - 1];
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int l = 0;
        int h = 0;
        for (char c: s) {
            if (c == '(') {
                l++;
                h++;
            } else if (c == ')') {
                l--;
                h--;
            } else {
                l--;
                h++;
            }
            if (h < 0) {
                return false;
            }
            if (l < 0) l = 0;
        }
        return l == 0;
    }
};

int main() {
    Solution s;

    // cout << s.checkValidString("()") << endl;
    // cout << s.checkValidString("())") << endl;
    cout << s.checkValidString("()*") << endl;
    cout << s.checkValidString("(*") << endl;
    cout << s.checkValidString("*(") << endl;
    cout << s.checkValidString("*(**(") << endl;
    cout << s.checkValidString("***))") << endl;
    cout << s.checkValidString("(*)") << endl;
    cout << s.checkValidString("(*))") << endl;
}