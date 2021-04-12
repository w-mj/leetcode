#include "defines.h"

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> pre;
        for (auto &x: prerequisites) {
            pre[x[1]].push_back(x[0]);
        }
        vector<bool> course(numCourses, false);
        bool finish = false;
        while (!finish) {
            finish = true;
            for (size_t i = 0; i < course.size(); i++) {
                if (course[i])
                    continue;
                if (pre[i].size() == 0) {
                    course[i] = true;
                    finish = false;
                } else {
                    for (auto it = pre[i].begin(); it != pre[i].end(); ) {
                        if (course[*it]) {
                            finish = false;
                            pre[i].erase(it);
                        } else {
                            ++it;
                        }
                    }
                }
            }
        }
        for (auto x: course)
            if (x == false)
                return false;
        return true;
    }
};