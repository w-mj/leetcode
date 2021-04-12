#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto x: lists) {
            if (x != nullptr) pq.push(x);
        }

        ListNode *head = nullptr, *cursor;
        while (!pq.empty()) {
            ListNode *t = pq.top();
            pq.pop();
            if (t->next != nullptr) {
                pq.push(t->next);
            }
            t->next = nullptr;
            if (head == nullptr) {
                head = t;
                cursor = t;
            } else {
                cursor->next = t;
                cursor = t;
            }
        }
        
        return head;
    }
};


int main(void) {
    Solution s;
    return 0;
}

#endif