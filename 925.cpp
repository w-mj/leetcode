#include "defines.h"

class Solution {
public:
 bool isLongPressedName(string name, string typed) { 
    int ni = 0, ti = 0;
    while (ni < name.size()) {
        if (name[ni] == typed[ti]) {
            if (name[ni + 1] != typed[ti + 1])
                while (typed[ti] == typed[ti + 1]) ti++;
            ti++;
            ni++;
        } else
            return false;
    }
    return true;
 }
};

int main(void) {
    Solution s;

    cout << s.isLongPressedName("saeed", "ssaaedd");
    return 0;
}