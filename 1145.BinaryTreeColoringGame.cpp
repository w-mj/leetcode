#include "defines.h"

#define RED -1
#define BLUE -2
#define NONE -3
class Solution {
public:
    bool check(int i, int color, int another) {
        step = 0;
        int todo[] = {i / 2, i * 2, i * 2 + 1};
        // vector<int> todo = {i / 2, i * 2, i * 2 + 1};
        for (int i = 0; i < 3; i++) {
            int t = todo[i];
            if (t > 0 && t <= n && tree[t] > 0) {
                step = 1;
                int a = tree[t];
                tree[t] = color;
                cnt++;
                if (game(another))
                    return true;
                tree[t] = a;
                cnt--;
            }
        }
        return false;
    }
    bool result() {
        int blue = 0;
        int red = 0;
        for (int i = 1; i <= n; i++) {
            if (tree[i] == RED)
                red++;
            else if (tree[i] == BLUE)
                blue++;
        }
        return blue > red;
    }
    bool game(int turn) {
        if (cnt == n)
            return result();
        int ano;
        if (turn == RED)
            ano = BLUE;
        else
            ano = RED;
         step = 0;
         int step1 = 0;
        for (int i = 1; i <= n; i++) {
            if (tree[i] == turn) {
                if (check(i, turn, ano))
                    return true;
                if (step == 1)
                    step1 = 1;
            }
            
        }
        if (step1 == 0)
            game(ano);
        return false;
    }

    int tree[128] = {0};
    void walk(TreeNode *root) {
        if (root == nullptr)
            return;
        tree[root->val] = root->val;
        walk(root->left);
        walk(root->right);
    }
    int n;
    int step;
    int cnt = 0;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->n = n;
        this->cnt = 0;
        for (size_t i = 0; i < 128; i++)
            tree[i] = i;
        walk(root);
        tree[x] = RED;
        cnt = 2;
        for (int i = 1; i <= n; i++) {
            if (tree[i] > 0) {
                int a = tree[i];
                tree[i] = BLUE;
                if(game(RED)) {
                    return true;
                }
                tree[i] = a;
            }
        }
        return false;
    }
};

int main(void) {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    Solution s;
    cout << s.btreeGameWinningMove(nullptr, 5, 2);
}