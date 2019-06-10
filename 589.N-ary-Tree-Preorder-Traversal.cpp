#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<Node*> st;
        Node* cur = root;
        st.push(root);
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            for (vector<Node*>::reverse_iterator it = cur->children.rbegin(); it != cur->children.rend(); it++)
                st.push(*it);
        }
        return ans;
    }
};
int main(void) {
    Solution s;
    return 0;
}

#endif