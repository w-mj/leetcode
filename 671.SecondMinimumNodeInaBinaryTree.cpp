#include "defines.h"


class Solution {
public:
    int min1;
    long ans = LONG_MAX;

    void dfs(TreeNode* root) {
        if (root != nullptr) {
            if (min1 < root->val && root->val < ans) {
                ans = root->val;
            } else if (min1 == root->val) {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val;
        dfs(root);
        return ans < LONG_MAX ? (int) ans : -1;
    }
};

