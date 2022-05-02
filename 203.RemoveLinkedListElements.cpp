#include "defines.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode fake_head(val - 1);     
        fake_head.next = head;
        ListNode* cur = &fake_head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return fake_head.next;
    }
};