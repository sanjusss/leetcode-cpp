#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        auto fast = head;
        auto slow = head;
        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return slow;
    }
};