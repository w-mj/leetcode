/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifdef LOCAL_DEBUG
#include "defines.h"

#endif

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* new_head = head,*cursor = head;
        int len = 1;
        while (cursor->next!=nullptr) {
            len++;
            cursor = cursor->next;
        }
        cursor->next = head;
        k = k % len;
        k = len - k;
        k--;
        while(k--) {
            new_head = new_head->next;
        }
        head = new_head->next;
        new_head->next = nullptr;
        return head;
    }
};
