#pragma once
#include <cassert>
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
#include <bitset>
#include <list>
#include <numeric>
// #include <bits/stdc++.h>
#include <cctype>

#define START_TIMER int __start_timer = clock();
#define END_TIMER int __during_time = (clock() - __start_timer) * 1000 / CLOCKS_PER_SEC; \
        cout << "during " << __during_time << " ms." << endl;

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

void printList(const vector<int>& v) {
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

void printList(set<int>& v) {
    for (auto c: v) {
        cout << c << ' ';
    }
    cout << endl;
}

void printList(const vector<vector<int>>& vv) {
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


#define SKIPBLANK while (isblank(*s)) s++
#define UNEXPECTED fprintf(stderr, "Unexpected character %c in %s.\n", *s, __func__);
#define SETEND(x) if (endP != nullptr) *endP = (x)

int getInt(const char*s, const char **endP) {
    int current = 0;
    bool negative = false;
    int state = 0;
    while (true) {
        switch (state) {
            case 0: {
                if (isblank(*s)) {
                    // nothing happens;
                } else if (*s == '-') {
                    negative = true;
                } else if (isdigit(*s)) {
                    current = *s - '0';
                    state = 1;
                } else {
                    fprintf(stderr, "unexpected character %c in getInt.", *s);
                    SETEND(s);
                    if (negative) {
                        return -current;
                    }
                    return current;
                }
                break;
            }
            case 1: {
                if (isdigit(*s)) {
                    current = current * 10 + *s - '0';
                } else {
                    SETEND(s);
                    if (negative) {
                        return -current;
                    }
                    return current;
                }
                break;
            }
            default: {
                fprintf(stderr, "Wrong state %d in getInt.\n", state);
            }
        }
        s++;
    }
    if (negative) {
        return -current;
    }
    return current;
}

vector<int> getVectorOfInt(const char *s, const char **endP) {
    vector<int> result;
    int state = 0;
    int current = 0;
    bool negative = false;
    while (*s) {
        switch (state) {
            case 0: {
                assert(*s == '[');
                state = 1;
                break;
            }
            case 1: {
                if (isdigit(*s) || (*s == '-') || isblank(*s)) {
                    result.push_back(getInt(s, &s));
                }
                while (isblank(*s))
                    s++;
                if (*s == ']') {
                    SETEND(s + 1);
                    return result;
                } else if (*s == ',') {
                    // nothing happens
                } else {
                    fprintf(stderr, "unexpected character %c in getVectorOfInt.\n", *s);
                    return result;
                }
                break;
            }
        }
        s++;
    }
    return result;
}

vector<vector<int>> getVectorOfVectorOfInt(const char *s, const char **endP) {
    vector<vector<int>> result;
    SKIPBLANK;
    if (*s != '[') {
        fprintf(stderr, "unexpected character %c in getVectorOfVectorOfInt.\n", *s);
        return result;
    }
    s++;
    SKIPBLANK;
    while (*s != ']') {
        if (*s != '[') {
            UNEXPECTED;
            return result;
        }
        result.emplace_back(getVectorOfInt(s, &s));
        SKIPBLANK;
        if (*s == ',') {
            s++;
        };
        SKIPBLANK;
    };
    SETEND(s + 1);
    return result;
}