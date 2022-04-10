#include "defines.h"



class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        unordered_map<TreeNode*, int> num;
        vector<int> parent;
        queue<TreeNode*> q;
        vector<TreeNode*> leaves;
        leaves.reserve(2048);
        num[root] = 0;
        parent.push_back(0);
        q.push(root);

        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (n->left != nullptr) {
                num[n->left] = parent.size();
                parent.push_back(num[n]);
                q.push(n->left);
            }
            if (n->right != nullptr) {
                num[n->right] = parent.size();
                parent.push_back(num[n]);
                q.push(n->right);
            }
            if (n->left == nullptr && n->right == nullptr) {
                leaves.push_back(n);
            }
        }

        for (int i = 0; i < leaves.size(); i++) {
            TreeNode* l1 = leaves[i];
            for (int j = i + 1; j < leaves.size(); j++) {
                TreeNode *l2 = leaves[j];
                int dis = 0;
                int n1 = num[l1];
                int n2 = num[l2];
                while (n1 != n2) {
                    if (n1 > n2) {
                        n1 = parent[n1];
                    } else {
                        n2 = parent[n2];
                    }
                    dis++;
                    if (dis > distance) {
                        break;
                    }
                }
                if (dis <= distance) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};

int main(void) {
    Solution s;
    TreeNode* root = getTree("[7,1,4,6,null,5,3,null,null,null,null,null,2]");
    cout << s.countPairs(root, 3) << endl;
}