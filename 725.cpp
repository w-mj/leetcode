#include "defines.h"
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* cursor = root;
        while (cursor) {
            length += 1;
            cursor = cursor -> next;
        }
        int remain = length / k;
        int plus_1 = length % k;
        cursor = root;
        vector<ListNode*> ans;
        for (int i = 0; i < k && cursor; i++) {
            ListNode* head = new ListNode(0);
            ans.push_back(head);
            for (int j = 0; j < remain + (plus_1 > 0); j++) {
                if (j == 0) {
                    head->val = cursor->val;
                }
                else {
                    head->next = new ListNode(cursor->val);
                    head = head->next;
                }
                cursor = cursor -> next;
            }
            if (plus_1) plus_1--;
        }
        while (ans.size() < k)
            ans.push_back(nullptr);
        return ans;
    }
};

int main(void) {
    Solution s;
    ListNode *list = makeList({1, 2, 3, 4, 5, 6, 7});
    auto a = s.splitListToParts(list, 3);
    for (auto b : a)
        printList(b);
}