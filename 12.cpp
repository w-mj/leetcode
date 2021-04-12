#include "defines.h"

class Solution {
public:
    map<int, string> m;
    string repeat_str(const string& s, int cnt) {
        string ans;
        while (cnt --) ans += s;
        return ans;
    }

    Solution () {
        m.insert(make_pair(1, "I"));
        m.insert(make_pair(5, "V"));
        m.insert(make_pair(10, "X"));
        m.insert(make_pair(50, "L"));
        m.insert(make_pair(100, "C"));
        m.insert(make_pair(500, "D"));
        m.insert(make_pair(1000, "M"));
        m.insert(make_pair(2000, "MM"));
        m.insert(make_pair(3000, "MMM"));

        int t = 1;
        for (int i = 2; t < 1000; i ++ ) {
            switch (i) {
            case 2:
            case 3:
                m.insert(make_pair(i * t, repeat_str(m[1 * t], i))); 
                break;
            case 4:
                m.insert(make_pair(i * t, m[1 * t] + m[5 * t]));
                break;
            case 6:
            case 7:
            case 8:
                m.insert(make_pair(i * t, m[5 * t] + repeat_str(m[1 * t], i - 5)));
                break;
            case 9:
                m.insert(make_pair(i * t, m[1 * t] + m[10 * t]));
                t *= 10;
                i = 1;
                break;
            }
        }
    }
    string intToRoman(int num) {
        string str = "";
        while (num) {
            if (num >= 1000) {
                str.append(m[(num / 1000) * 1000]);
                num = num % 1000;
            } else if (num >= 100) {
                str.append(m[(num / 100) * 100]);
                num = num % 100;
            } else if (num >= 10) {
                str.append(m[(num / 10) * 10]);
                num = num % 10;
            } else {
                str.append(m[num]);
                num = num % 1;
            }
        }
        return str;
    }
};

int main(void) {
    Solution s;
    cout << s.intToRoman(20) << endl;

    return 0;
}