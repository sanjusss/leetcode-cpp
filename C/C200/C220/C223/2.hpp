#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a = nullptr;
        ListNode* b = head;
        ListNode* root = head;
        for (int i = 1; i < k; ++i) {
            head = head->next;
        }

        a = head;
        while (head->next != nullptr) {
            head = head->next;
            b = b->next;
        }

        swap(a->val, b->val);

        return root;
    }
};