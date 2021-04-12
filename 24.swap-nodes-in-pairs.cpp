/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.12%)
 * Total Accepted:    283.1K
 * Total Submissions: 655K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* c = head, *n, *p;
        p = head;
        c = head->next->next;
        head = head -> next;
        head->next = p;
        p->next = c;
        while (c != NULL && c->next != NULL) {
            n = c->next;
            p->next = n;
            c->next = n->next;
            n->next = c;
            p = c;
            c = c->next;
        }
        return head;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    ListNode*r = s.swapPairs(&n1);
    while (r != NULL) {
        cout << r->val << " ";
        r = r->next;
    }
    return 0;
}

#endif

