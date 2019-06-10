#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <climits>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <queue>
#include <iterator>
#include <sstream>

#define START_TIMER int __start_timer = clock();
#define END_TIMER int __during_time = (clock() - __start_timer) * 1000 / CLOCKS_PER_SEC; \
        cout << "during " << __during_time << " ms." << endl;
#define ll long long

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
    void print(set<UndirectedGraphNode*>* sett=nullptr) {
        bool head = false;
        if (!sett) {
            sett = new set<UndirectedGraphNode*>;
            head = true;
        }
        sett->insert(this);
        cout << label;
        for (auto n: neighbors) {
            cout << "," << n->label;
        }
        cout << "#";
        for (auto n: neighbors) {
            if (sett->find(n) == sett->end())
                n->print(sett);
        }
        if (head) {
            delete sett;
            cout << endl;
        }
    }
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

ListNode* makeList(vector<int> list) {
    if (list.empty()) return nullptr;
    ListNode* head = new ListNode(list[0]);
    ListNode* cursor = head;
    for (vector<int>::iterator iter = list.begin() + 1; iter != list.end(); iter++) {
        cursor->next = new ListNode(*iter);
        cursor = cursor -> next;
    }
    return head;
}

void printList(ListNode* list) {
    while(list) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

void printList(vector<int>& v) {
    for (int c: v) {
        cout << c << ' ';
    }
    cout << endl;
}

void printList(vector<string>& v) {
    for (string c: v) {
        cout << c << ' ';
    }
    cout << endl;
}

void printList(vector<vector<int>>& vv) {
    for (auto& v : vv) {
        for (int c : v) {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void printList(vector<vector<string>>& vv)
{
    for (auto& v : vv) {
        for (string& c : v) {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl;
}