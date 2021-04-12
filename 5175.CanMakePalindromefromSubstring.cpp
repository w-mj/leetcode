#include "defines.h"
//[true,false,true,true,true,true,true,false,true,false,true,true,true]
int sig[10000][10000] = {0};
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        for (int i = 0; i < s.size(); i++)
            sig[i][i] = 1;
        for (int i = 0; i < s.size(); i++) {
            int count[26] = {0};
            memset(count, 0, 26 * sizeof(int));

            count[s[i] - 'a'] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (count[s[j] - 'a'] & 1) {
                    sig[i][j] = sig[i][j - 1] - 1;
                } else {
                    sig[i][j] = sig[i][j - 1] + 1;
                }
                count[s[j] - 'a']++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                cout << sig[i][j] << " ";
            }
            cout << endl;
        }
        vector<bool> result;
        for (const auto& q: queries) {
            int single = sig[q[0]][q[1]];
            result.emplace_back(single / 2 <= q[2]);
        }
        return result;
    }
};

int main(void) {
    Solution s;
    auto a = vector<vector<int>>();
    s.canMakePaliQueries("abcda", a);
}