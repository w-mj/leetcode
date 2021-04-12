/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

#ifdef LOCAL_DEBUG
#include "defines.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *ans = nullptr, *cur;
        if (l1->val < l2->val) {
            ans = l1;
            l1 = l1->next;
        } else {
            ans = l2;
            l2 = l2->next;
        }
        cur = ans;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != nullptr) cur->next = l1;
        if (l2 != nullptr) cur->next = l2;
        return ans;
    }
};

int main(void) {
    Solution s;
    return 0;
}

#endif