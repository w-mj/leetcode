#include "defines.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s1s = accumulate(students.begin(), students.end(), 0);
        int s0s = students.size() - s1s;
        for (int a: sandwiches) {
            if (a == 0) {
                if (s0s == 0) {
                    break;
                }
                s0s --;
            } else if (a == 1) {
                if (s1s == 0) {
                    break;
                }
                s1s --;
            }
        }
        return s0s + s1s;
    }
};