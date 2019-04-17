#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        shared_ptr<ListNode> root(new ListNode(0));
        ListNode* prev = root.get();
        prev->next = head;
        ListNode* current = head;
        while (current != nullptr)
        {
            if (current->val == val)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        return root->next;
    }
};