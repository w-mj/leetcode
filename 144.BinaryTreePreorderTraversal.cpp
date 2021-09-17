#include "defines.h"

class Solution {
public:
    vector<int> ans;
    void f(TreeNode* root) {
        ans.push_back(root->val);
        if (root->left != nullptr)
            f(root->left);
        if (root->right != nullptr)
            f(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        if (root != nullptr)
            f(root);
        return ans;
    }
};