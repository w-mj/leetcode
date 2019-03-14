#include "defines.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;
        for (int r = 1; r <= numRows; r++) {
            vector<int> row(r, 1);
            for (int i = 1; i < (int)row.size() - 1; i++) {
                row[i] = result[result.size() - 1][i - 1] + result[result.size() - 1][i];
            }
            result.emplace_back(row);
        }
        return result;
    }
};

int main(void) {
    Solution s;
    vector<vector<int>> result = s.generate(6);
    printList(result);
    return 0;
}