#include "defines.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v(2020, 0);
        for (auto x: arr) {
            v[x + 1000] += 1;
        }
        sort(v.begin(), v.end());
        size_t i = 0;
        while (v[i] == 0)
            i++;
        i++;
        for (; i < v.size(); i++) {
            if (v[i - 1] == v[i])
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
    vector<int> v1 = {1,2,2,1,1,3};
    vector<int> v2 = {1, 2};
    vector<int> v3 = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << s.uniqueOccurrences(v1) << endl;
    cout << s.uniqueOccurrences(v2) << endl;
    cout << s.uniqueOccurrences(v3) << endl;

}