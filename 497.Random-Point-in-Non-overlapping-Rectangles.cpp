#ifdef LOCAL_DEBUG
#include "defines.h"


#define ull unsigned long long
class Solution {
public:
    struct Rect {
        int x1, y1, x2, y2;
        ull lower, upper;
        Rect(int x1, int y1, int x2, int y2, ull low, ull up): 
        x1(x1), y1(y1), x2(x2), y2(y2), lower(low), upper(up) {}
    };

    vector<Rect> rv;
    ull max_n;
    Solution(vector<vector<int>>& rects) {
        srand(time(0));
        ull last = 0;
        max_n = 0;
        for (const auto& r: rects) {
            ull area = (abs(r[2] - r[0]) + 1) * (abs(r[3] - r[1]) + 1);
            rv.emplace_back(r[0], r[1], r[2], r[3], max_n, max_n + area);
            cout << rv.back().lower <<  " "<<  rv.back().upper << endl;
            last = area;
            max_n += area;
        }
    }
    
    vector<int> pick() {
        ull w_r = ((ull)rand()) % (max_n);
        for (const auto& r: rv) {
            if (r.lower <= w_r && r.upper >= w_r) {
                int x = min(r.x1, r.x2) + (rand() % (abs(r.x2 - r.x1) + 1));
                int y = min(r.y1, r.y2) + (rand() % (abs(r.y2 - r.y1) + 1));
                return {x, y};
            }
        }
        return {-1, -1, -1};
    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
int main(void) {
    Solution s;
    return 0;
}

#endif