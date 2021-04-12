#include "defines.h"

#define BLUE 2
#define RED 1
class Solution {
public:
    struct Node {
        int node;
        int len;
        int lastColor = 0;
        Node(int n, int l, int c): node(n), len(l), lastColor(c) {}
        bool operator<(const Node& ano) const {
            return len > ano.len;
        }
        bool operator==(const Node& ano) const {
            return node == ano.node && lastColor == ano.lastColor;
        }
    };                       

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        int path[100][100] = {0};
        int seek[100];
        int mind[100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                path[i][j] = 0;
            seek[i] = -1;
            mind[i] = 999999;
        }
        mind[0] = 0;
        seek[0] = 0;
        for (auto x: red_edges)
            path[x[0]][x[1]] |= RED;
        for (auto x: blue_edges)
            path[x[0]][x[1]] |= BLUE;
        
        priority_queue<Node> qu;
        vector<Node> vis;
        qu.emplace(0, 0, 3);
        while (!qu.empty()) {
            auto cur = qu.top();
            qu.pop();
            if (find(vis.begin(), vis.end(), cur) != vis.end() || cur.len > n * n)
                continue;
            vis.push_back(cur);
            if (cur.len < mind[cur.node])
                mind[cur.node] = cur.len;
            for (int j = 0; j < n; j++) {
                if ((cur.lastColor == 3 && path[cur.node][j] > 0)|| 
                    ((cur.lastColor == RED)&&(path[cur.node][j] & BLUE)) ||
                    ((cur.lastColor == BLUE)&&(path[cur.node][j] & RED))) {
                    // if (mind[j] > mind[cur.node] + 1) {
                    //     mind[j] = mind[cur.node] + 1;
                    //     seek[j] = cur.node;
                        if (cur.lastColor == RED)
                            qu.emplace(j, cur.len + 1, BLUE);
                        else if (cur.lastColor == BLUE)
                            qu.emplace(j, cur.len + 1, RED);
                        else 
                            qu.emplace(j, cur.len + 1, path[cur.node][j]);
                    // }
                }
                // } else if (
                //     ((cur.lastColor == RED)&&(path[cur.node][cur.node] & BLUE )&&(path[cur.node][j] & RED) )||
                //      ((cur.lastColor == BLUE)&& (path[cur.node][cur.node] & RED )&& (path[cur.node][j] & BLUE)) ){
                //         if (cur.lastColor == RED)
                //             qu.emplace(j, cur.len + 2, BLUE);
                //         else
                //             qu.emplace(j, cur.len + 2, RED);
                //     }
            }
        }
        vector<int> ans = {0};
        for (int j = 1; j < n; j++) {
            if (mind[j] == 999999)
                ans.push_back(-1);
            else 
                ans.push_back(mind[j]);
        }
        return ans;
    }
};

int main(void) {
    vector<vector<int>> r = {{1,5},{2,2},{5,5},{3,0},{4,5},{2,4},{4,1},{1,0},{1,2},{5,2},{2,3},{0,1}};
    vector<vector<int>> b = {{4,4},{2,5},{1,1},{5,4},{3,3}};
    Solution s;
    printList(s.shortestAlternatingPaths(6, r, b));
}