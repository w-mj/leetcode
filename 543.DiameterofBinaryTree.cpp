#include "defines.h"

class Solution {
public:
    pair<int, int> w(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return {0, 0};
        }
        pair<int, int> left = make_pair(-1, -1);
        pair<int, int> right = make_pair(-1, -1);
        if (root->left != nullptr) {
            left = w(root->left);
        }
        if (root->right != nullptr) {
            right = w(root->right);
        }
        int depth = max(left.second, right.second) + 1;
        int ans = max(left.first, max(right.first, left.second + right.second + 2));
        return {ans, depth};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return w(root).first;
    }
};

int main(void) {
    Solution s;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << s.diameterOfBinaryTree(root) << endl;
    root = new TreeNode(1, new TreeNode(2), nullptr);
    cout << s.diameterOfBinaryTree(root) << endl;
}