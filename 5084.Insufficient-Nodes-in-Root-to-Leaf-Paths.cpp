#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    stack<TreeNode*> parent;
    TreeNode* sufficientSubset(TreeNode* root, long long limit) {

        // parent.emplace(root);
        if (root->left != nullptr)
            root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right != nullptr)
            root->right = sufficientSubset(root->right, limit - root->val);
        if (root->right == nullptr && root->left == nullptr) {
            if (limit > 0)
                return nullptr;
        }
        return root;
    }
};
int main(void) {
    Solution s;
    return 0;
}

#endif

