#include "defines.h"
#include <queue>

string pattern[][16] = {
    {"0000", "1110"},
    {"1000", "1110"},
    {"0100", "1101"},
    {"1100", "1110"},
    {"0010", "1101"},
    {"1010", "1101"},
    {"0110", "1011"},
    {"1110", "1110"},
    {"0001", "1101"},
    {"1001", "1101"},
    {"0101", "1011"},
    {"1101", "1101"},
    {"0011", "1011"},
    {"1011", "1011"},
    {"0111", "0111"},
    {"1111", "1111"},
};


bool check_pattern(const string& str, int i, const string& pat) {
    return str[i] == pat[0] &&
           str[i + 1] == pat[1] &&
           str[i + 2] == pat[2] &&
           str[i + 3] == pat[3];
}

void replace_pattern(string& str, int i, const string& pat) {
    str[i] = pat[0];
    str[i + 1] = pat[1];
    str[i + 2] = pat[2];
    str[i + 3] = pat[3];
}


class Solution {
public:
    string maximumBinaryString(string binary) {
        int j_start = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                for (int j = max(i + 1, j_start); j < binary.size(); j++) {
                    if (binary[j] == '0') {
                        if (j > i + 1) {
                            binary[i + 1] = '0';
                            binary[j] = '1';
                        }
                        binary[i] = '1';
                        j_start = j + 1;
                        break;
                    }
                }
            }
        }
        return binary;
    }
};


string bure(const string& origin) {
    set<string> visit;
    queue<string> que;
    que.push(origin);
    string ans(origin.size(), '0');
    while (!que.empty()) {
        string str = que.front();
        que.pop();
        ans = max(ans, str);
        if (visit.find(str) != visit.end()) {
            continue;
        }
        visit.insert(str);

        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == '0' && str[i + 1] == '0') {
                str[i] = '1';
                if (visit.find(str) == visit.end()) {
                    que.push(str);
                }
                str[i] = '0';
            } else if (str[i] == '1' && str[i + 1] == '0') {
                str[i] = '0';
                str[i + 1] = '1';
                if (visit.find(str) == visit.end()) {
                    que.push(str);
                }
                str[i] = '1';
                str[i + 1] = '0';
            }
        }
    }
    return ans;
}

void print(int len) {
    Solution s;
    string str(len, '0');
    for (int i = 0; i < (1 << len); i++) {
        int num = i;
        for (int j = 0; j < len; j++) {
            str[j] = (num & 1) + '0';
            num = num >> 1;
        }
        auto b = bure(str);
        auto a = s.maximumBinaryString(str);
        cout << str << " --> " << bure(str) << " === " << a << "   " << (a == b) << endl;
    }
}

int main(void) {
    // print(3);
    print(4);
    print(5);
}