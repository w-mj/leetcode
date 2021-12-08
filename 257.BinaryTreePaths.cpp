#include "defines.h"


class Solution {
public:
    vector<string> ans;
    void dfs(vector<int>& res, TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            stringstream ss;
            for (int i: res) {
                ss << i << "->";
            }
            ss << root->val;
            ans.push_back(ss.str());
        } else {
            res.push_back(root->val);
            if (root->left != nullptr)
                dfs(res, root->left);
            if (root->right != nullptr)
                dfs(res, root->right);
            res.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }
        vector<int> res;
        dfs(res, root);
        return ans;
    }
};