#include "defines.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaceCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                spaceCnt++;
                if (spaceCnt == k) {
                    return s.substr(0, i);
                }
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.truncateSentence("Hello how are you Contestant", 4) << "END" << endl;
    cout << s.truncateSentence("What is the solution to this problem", 4) << "END" << endl;
    cout << s.truncateSentence("chopper is not a tanuki", 2) << "END" << endl;
    cout << s.truncateSentence("chopper", 1) << "END" << endl;
}