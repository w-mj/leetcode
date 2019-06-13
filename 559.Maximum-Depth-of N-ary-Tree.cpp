/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include "defines.h"

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int maxt = 1;
        for (Node* n: root->children) {
            maxt = max(maxt, maxDepth(n) + 1);
        }
        return maxt;
    }
};