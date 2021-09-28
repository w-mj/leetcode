#include "defines.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val > q->val && root->val > p->val) {
                root = root->left;
            } else if(root->val < p->val && root->val < q->val) {
                root = root->right;        
            } else {
                return root;
            }
        }
        return root;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(6,
        new TreeNode(2, 
            new TreeNode(0), 
            new TreeNode(4, 
                new TreeNode(3), 
                new TreeNode(5)
                )
            ),
        new TreeNode(8, 
            new TreeNode(7), 
            new TreeNode(9)
        )
    );
    cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;
}