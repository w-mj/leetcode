#include "defines.h"

class Tire {
    struct Node {
        Node* link[2] = {};
    };

    Node *root = new Node();

    public:
    
    void insert(int num) {
        Node *node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->link[bit] == nullptr) {
                node->link[bit] = new Node();
            }
            node = node->link[bit];
        }
    }

    int maximizeXor(int num) {
        Node* node = root;
        if (root->link[0] == nullptr && root->link[1] == nullptr) {
            return -1;
        }
        int maxVal = 0;
        for(int i=31; i>=0; i--){
             int bit =(num>>i) & 1;
             if(node->link[!bit] != nullptr){
                 maxVal = maxVal | (1<< i);
                 node = node->link[!bit];
             } else {
                 node = node->link[bit];
             }
        }
        return maxVal; 
    }
};

struct Triple {
    int a, b, c;
    Triple(int a, int b, int c): a(a), b(b), c(c) {}
    bool operator<(const Triple& ano) const {
        if (a != ano.a) return a < ano.a;
        if (b != ano.b) return b < ano.b;
        return c < ano.c;
    }

    bool operator==(const Triple& ano) const {
        return a == ano.a && b == ano.b && c == ano.c;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Tire tire;
        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());

        vector<Triple> ques;
        for (int i = 0; i < queries.size(); i++) {
            ques.emplace_back(queries[i][1], queries[i][0], i);
        }

        sort(ques.begin(), ques.end());

        int insert_nums = 0;
        for (int i = 0; i < ques.size(); i++) {
            while (insert_nums < nums.size() && nums[insert_nums] <= ques[i].a) {
                tire.insert(nums[insert_nums]);
                insert_nums++;
            }
            ans[ques[i].c] = tire.maximizeXor(ques[i].b);
        }
        
        return ans;
    }
};
