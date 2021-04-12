#include "defines.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < v.size(); i++) {
            int sum = v[i];
            if (sum == 0)
                continue;
            for (int j = i + 1; j < v.size(); j++) {
                sum += v[j];
                if (sum == 0) {
                    for (int t = i; t <= j; t++)
                        v[t] = 0;
                    break;
                }
            }
        }
        head = new ListNode(0);
        auto cursor = head;
        for (auto x: v) {
            if (x != 0) {
                cursor->next = new ListNode(x);
                cursor = cursor->next;
            }
        }
        return head->next;
    }
};