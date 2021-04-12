#include "defines.h"

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_val = 0;
        int level = 1;
        int max_level = 1;
        while (!q.empty()) {
            int level_size = q.size();
            int level_val = 0;
            while (level_size--) {
                auto a = q.front();
                q.pop();
                level_val += a->val;
                if (a->left != nullptr)
                    q.push(a->left);
                if (a->right != nullptr)
                    q.push(a->right);
            }
            if (level_val > max_val) {
                max_level = level;
                max_val = level_val;
            }
            level++;
        }
        return max_level;
    }
};