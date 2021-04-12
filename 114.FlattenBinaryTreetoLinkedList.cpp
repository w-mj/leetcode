#include "defines.h"

class Solution {
public:

    TreeNode *subTree(TreeNode *root) {
        TreeNode *tail = root;
        if (root->right != nullptr) {
            tail = subTree(root->right);
        }
        if (root->left != nullptr) {
            TreeNode *taill = subTree(root->left);
            if (root->right == nullptr) {
                tail = taill;
            }
            taill->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return tail;
    }

    void flatten(TreeNode* root) {
        if (root != nullptr)
        subTree(root);
    }
};