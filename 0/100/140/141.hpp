#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool hasCycle(ListNode* head) 
    {
        auto fast = head;
        auto slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};