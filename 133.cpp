#include "defines.h"



class Solution {
public:
    map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        UndirectedGraphNode* ans = new UndirectedGraphNode(node->label);
        mapping.insert(make_pair(node, ans));
        for (auto n: node->neighbors) {
            if (mapping.find(n) != mapping.end())
                ans->neighbors.push_back(mapping[n]);
            else
                ans->neighbors.push_back(this->cloneGraph(n));
        }
        return ans;
    }
};

int main() {
    UndirectedGraphNode node0(0), node1(1), node2(2);
    node0.neighbors.push_back(&node1);
    node0.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node2);
    node2.neighbors.push_back(&node2);
    node0.print();
    Solution s;
    UndirectedGraphNode* ans = s.cloneGraph(&node0);
    ans->print();
}
