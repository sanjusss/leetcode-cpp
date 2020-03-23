#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode root(INT_MIN);
        root.next = head;
        ListNode* slow = &root;
        ListNode* fast = nullptr;
        while (slow->next != nullptr && slow->next->next != nullptr)
        {
            if (slow->next->val == slow->next->next->val)
            {
                fast = slow->next->next;
                do
                {
                    fast = fast->next;
                } while (fast != nullptr && fast->val == slow->next->val);
                slow->next = fast;
            }
            else
            {
                slow = slow->next;
            }
        }

        return root.next;
    }
};