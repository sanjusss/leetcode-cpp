#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode* p = head;
        int length = 0;
        while (p != nullptr)
        {
            p = p->next;
            ++length;
        }

        k %= length;
        if (k == 0)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;
        for (int i = 0; i < length - k; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        p = current;
        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = head;
        return current;
    }
};