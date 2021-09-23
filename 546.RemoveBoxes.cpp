#include "defines.h"

class Solution {
public:
    map<vector<int>, int> cache;

    int removeBoxes(vector<int> box) {
        if (box.size() == 1) {
            return 1;
        }
        if (cache.find(box) != cache.end()) {
            return cache[box];
        }
        int ans = 0;
        int i = 0;
        while (i < box.size()) {
            int j = i + 1;
            while (j < box.size() && box[i] == box[j]) {
                j++;
            }
            vector<int> remain;
            remain.insert(remain.end(), box.begin(), box.begin() + i);
            remain.insert(remain.end(), box.begin() + j, box.end());
            ans = max(ans, (j - i) * (j - i) + removeBoxes(remain));
            i = j;
        }
        cache[box] = ans;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.removeBoxes({1,3,2,2,2,3,4,3,1}) << endl;
    s.cache.clear();
    cout << s.removeBoxes({1,1,1}) << endl;
    s.cache.clear();
    cout << s.removeBoxes({1}) << endl;
    s.cache.clear();
}