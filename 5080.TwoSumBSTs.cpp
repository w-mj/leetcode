#include "defines.h"

class Solution {
public:
    bool is_in(TreeNode* tree, int target) {
        while (tree != nullptr && tree->val != target) {
            if (tree->val > target)
                tree = tree->left;
            else
                tree = tree->right;
        }
        return tree != nullptr;
    }

    bool walk(TreeNode * tree1, TreeNode* tree2, int target) {
        cout << "work tree1->val=" << tree1->val << endl;
        if (is_in(tree2, target - tree1->val))
            return true;
        if (tree1->left != nullptr && walk(tree1->left, tree2, target))
            return true;
        if (tree1->right != nullptr)
            return walk(tree1->right, tree2, target);
        return false;
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return walk(root1, root2, target);
    }
};

int main(void) {
    Solution s;
}