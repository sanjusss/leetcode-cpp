#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        shared_ptr<ListNode> rootOdd(new ListNode(0));
        auto odd = rootOdd.get();
        shared_ptr<ListNode> rootEven(new ListNode(0));
        auto even = rootEven.get();
        bool isEven = true;
        while (head != nullptr)
        {
            if (isEven)
            {
                even->next = head;
                even = head;
            }
            else
            {
                odd->next = head;
                odd = head;
            }

            isEven = !isEven;
            head = head->next;
        }

        odd->next = nullptr;
        even->next = rootOdd->next;
        return rootEven->next;
    }
};