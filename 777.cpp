#include "defines.h"

class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        while (i < start.size()) {
            if (start[i] == end[i]) i++;
            else {
                if (start[i] == 'X' && end[i] == 'L') {
                    int j = i + 1;
                    while (j < start.size() && start[j] == 'X') j++;
                    if (start[j] == 'L') {
                        start[j] = 'X';
                        start[i] = 'L';
                    } else return false;
                } else if (start[i] == 'R' && end[i] == 'X') {
                    int j = i + 1;
                    while (j < end.size() && end[j] == 'X') j++;
                    if (end[j] == 'R') {
                        end[j] = 'X';
                        end[i] = 'R';
                    } else return false;
                } else return false;
            }
        }
        return i == start.size();
    }
};

int main(void) {
    Solution s;
    cout << s.canTransform("XLXRRXXRXX", "LXXXXXXRRR");
    return 0;
}