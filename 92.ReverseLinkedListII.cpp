#include "defines.h"


#define PUSH(cnt) (left + right)

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> st;
        int cnt = 1;
        int push = (left + right) / 2;
        int pop = push;
        if ((left + right) % 2 == 0) {
            push -= 1;
            pop += 1;
        }
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cnt >= left && cnt <= push) {
                st.push(cur);
            } else if (cnt >= pop && cnt <= right) {
                ListNode *n = st.top();
                st.pop();
                swap(n->val, cur->val);
            }
            cur = cur->next;
            cnt++;
        }
        return head;
    }
};

int main() {
    Solution s;
    printList(s.reverseBetween(makeList({1, 2, 3, 4, 5}), 2, 4));
    printList(s.reverseBetween(makeList({1, 2, 3, 4, 5}), 2, 5));
    printList(s.reverseBetween(makeList({5}), 1, 1));
}