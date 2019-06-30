#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int t = 1;
        bool reverse = false;
        while (t <= label) {
            t = t << 1;
            reverse = !reverse;
        }
        reverse = !reverse;
        t >>= 1;
        while (label > 0) {
            cout << label << " " << reverse  << " " << t << endl;
            ans.insert(ans.begin(), label);

            if (reverse) {
                label = (t - 1) + (t << 1) - label;
            }

            label = (label - 2) / 2 + 1;
            reverse = !reverse;
            t>>=1;

            if (reverse) {
                label = (t - 1) + (t << 1) - label;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> pathInZigZagTree(int label) {
//         int i = 0;
//         vector<int> t;
//         vector<int> ans;
//         int reverse = false;
//         t.push_back(1);
//         i = 1;
//         int level = 2;
//         while(i < label) {
//             if 
//             t.push_back(pow(2, level) - i);
//             i++;
//         }
//     }
// };

int main(void) {
    Solution s;
    auto t = s.pathInZigZagTree(26);
    printList(t);
    // for (int i = 2; i <= 16; i++) {
    //     t = s.pathInZigZagTree(i);
    //     printList(t);
    // }
    return 0;
}

#endif