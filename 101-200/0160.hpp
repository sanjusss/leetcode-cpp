#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //(a + c) + b = (b + c) + a
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        auto pA = headA;
        auto pB = headB;
        while (pA != pB)
        {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};