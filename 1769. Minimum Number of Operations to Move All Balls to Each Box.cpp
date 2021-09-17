#include "defines.h"

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0;
        int right = 0;
        int allMove = 0;
        vector<int> result(boxes.size(), 0);        

        for (int i = 0; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                right += 1;
                allMove += i;
            }
        }

        for (int i = 0; i < boxes.size(); i++) {
            result[i] = allMove;
            if (boxes[i] == '1') {
                left++;
                right--;
            }
            allMove = allMove - right + left;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.minOperations("110") << endl;
    cout << s.minOperations("001011") << endl;
}