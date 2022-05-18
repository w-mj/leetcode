#include "defines.h"

class Solution {
public:
    unordered_map<int, int> subSum;

    int calSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } if (root->left == nullptr && root->right == nullptr) {
            subSum[root->val]++;
            return root->val;
        } else {
            int n = root->val + calSum(root->left) + calSum(root->right);
            subSum[n]++;
            return n;
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        calSum(root);
        int maxv = 0;
        for (auto& item: subSum) {
            maxv = max(maxv, item.second);
        }
        vector<int> ans;
        for (auto& item: subSum) {
            if (item.second == maxv) {
                ans.push_back(item.first);
            }
        }
        return ans;
    }
};