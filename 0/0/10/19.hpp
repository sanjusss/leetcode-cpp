#pragma once

#include "leetcode.h"

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        shared_ptr<ListNode> root(new ListNode(0));
        root->next = head;
        auto second = root.get();
        for (int i = 0; i < n; ++i)
        {
            head = head->next;
        }

        while (head != nullptr)
        {
            head = head->next;
            second = second->next;
        }

        shared_ptr<ListNode> removed(second->next);
        second->next = second->next->next;
        return root->next;
    }
};