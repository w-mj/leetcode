#include "defines.h"

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = nullptr;
        TreeNode *cur = nullptr;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* c = root->left;
        while (!s.empty() || c) {
            while (c) {
                s.push(c);
                c = c->left;
            }
            c = s.top();
            s.pop();
            if (!res) res = cur = new TreeNode(c->val);
            else {
                cur -> right = new TreeNode(c->val);
                cur = cur->right;
            }
            c = c->right;
        }
        return res;
    }
};