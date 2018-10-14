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
#include <unordered_map>
#include <algorithm>
#include <cctype>

#define START_TIMER int __start_timer = clock();
#define END_TIMER int __during_time = (clock() - __start_timer) * 1000 / CLOCKS_PER_SEC; \
        cout << "during " << __during_time << " ms." << endl;


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

using namespace std;

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