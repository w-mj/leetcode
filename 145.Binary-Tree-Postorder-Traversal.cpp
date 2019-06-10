#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        unordered_set<TreeNode*> vis;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (vis.find(cur) != vis.end()) { 
                // 第二次
                ans.push_back(cur->val);
                cur = nullptr;
            } else {
                // 第一次
                vis.insert(cur);
                st.push(cur);
                cur = cur->right;
            }            
        }
        return ans;
    }
};
int main(void) {
    Solution s;
    return 0;
}

#endif