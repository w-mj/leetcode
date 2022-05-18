#include "defines.h"

class Solution {
public:
    bool check(int data[]) {
        for (int i = 'a'; i <= 'z'; i++) {
            int a = data[i];
            int b = data[i ^ 'a' ^ 'A'];
            if (a + b > 0 && a * b == 0) {
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int start_i = 0;
        int max_l = 0;
        int ans_i = 0;
        int window_size = s.size();
        while (window_size >= 2) {
            int data[128] = {0};
            for (int i = 0; i < window_size; i++) {
                data[s[i]]++;
            }
            for (int start = 0; start + window_size <= s.size(); start++) {
                if (check(data)) {
                    return s.substr(start, window_size);
                }
                if (start + window_size < s.size()) {
                    data[s[start]]--;
                    data[s[start + window_size]]++;
                }
            }
            window_size--;
        }
        return "";
    }
};

int main() {
    Solution s;
    cout << s.longestNiceSubstring("YazaAay") << endl;
}