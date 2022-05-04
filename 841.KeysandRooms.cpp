#include "defines.h"
#include <numeric>

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visit(rooms.size(), 0);
        stack<int> keys;
        keys.push(0);

        while (!keys.empty()) {
            int key = keys.top();
            keys.pop();

            if (visit[key] == 1) {
                continue;
            }

            visit[key] = 1;

            for (int k: rooms[key]) {
                if (visit[k] == 0) {
                    keys.push(k);
                }
            }
        }

        return accumulate(visit.begin(), visit.end(), 0) == rooms.size();
    }
};