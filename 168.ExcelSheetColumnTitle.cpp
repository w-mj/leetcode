#include "defines.h"


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        do {
            columnNumber--;
            ans.push_back((columnNumber) % 26 + 'A');
            columnNumber = columnNumber / 26;
        } while (columnNumber);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(701) << endl;
    cout << s.convertToTitle(2147483647) << endl;
}