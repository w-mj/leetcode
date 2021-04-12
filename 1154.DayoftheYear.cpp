#include "defines.h"


int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define runnian(a) (((a) % 400 == 0) || ((a) % 4 == 0 && (a) % 100 != 0))
#define toi(s) ((s) - '0')
#define toi2(s, n) (toi(s[n]) * 10 + toi(s[n+1]))
#define toi4(s, n) (toi2(s, n) * 100 + toi2(s, n + 2))
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        cout << year << " " << month << " " << day << endl;;
        if (runnian(year))
            days[2] = 29;
        else
            days[2] = 28;
        int ans = 0;
        for (int i = 1; i < month; i++) {
            ans += days[i];
        }
        ans += day;
        return ans;
    }
};

int main(void) {
    Solution s;
    cout << s.dayOfYear("2019-01-09") << endl;
    cout << s.dayOfYear("2019-01-09") << endl;
    cout << s.dayOfYear("2019-01-09") << endl;
    cout << s.dayOfYear("2004-03-01") << endl;

}