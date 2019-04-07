#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        shared_ptr<ListNode> root(new ListNode(0));
        auto head = root.get();
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l2 == nullptr
                || (l1 != nullptr && l1->val < l2->val))
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }

            head = head->next;
        }

        return root->next;
    }
};