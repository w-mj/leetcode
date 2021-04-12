#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:
    vector<TreeNode*> ans;
    set<int> to_del;
    vector<TreeNode*> to_pro;

    bool dd(TreeNode *r) {
        
        if (to_del.find(r->val) != to_del.end()) {
            if (r->left != nullptr && !dd(r->left))
                ans.emplace_back(r->left);
            if (r->right != nullptr && !dd(r->right))
                ans.emplace_back(r->right);
            return true;
        }
        if (r->left != nullptr && dd(r->left)) {
            r->left = nullptr;
        }
        if (r->right != nullptr && dd(r->right)) {
            r->right = nullptr;
        }
        return false;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ans.clear();
        for (auto x: to_delete)
            to_del.emplace(x);
        if (root != nullptr && !dd(root)){
            ans.emplace_back(root);
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif