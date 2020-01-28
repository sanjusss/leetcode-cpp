#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        auto root = head;
        if (root != nullptr)
        {
            while (head->next != nullptr)
            {
                if (head->val == head->next->val)
                {
                    head->next = head->next->next;
                }
                else
                {
                    head = head->next;
                }
            }
        }

        return root;
    }
};