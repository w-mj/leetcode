/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.98%)
 * Total Accepted:    355.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* queue[n], *prev[n] = {NULL};
        int i = 0;
        ListNode* cursor = head, *last;
        while (cursor != NULL) {
            queue[i] = cursor;
            last = cursor;
            cursor = cursor->next;
            if (cursor != NULL) {
                i = (i + 1) % n;
                prev[i] = last;
            }
        }
        i = (i + 1) % n;
        if (prev[i] == NULL || prev[i] == queue[i])
            head = queue[i]->next;
        else 
            prev[i]->next = queue[i]->next;
        // delete queue[i];
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
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    ListNode* r = s.removeNthFromEnd(&n1, 5);
    while(r != NULL) {
        cout << r->val << " ";
        r = r->next;
    }

    return 0;
}

#endif

