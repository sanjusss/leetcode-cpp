#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* detectCycle(ListNode* head) 
    {
        bool hasCycle = false;
        auto slow = head;
        auto fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle == false)
        {
            return nullptr;
        }

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    ////Ç¿ÐÐ×·Öð
    //ListNode* detectCycle(ListNode* head)
    //{
    //    bool hasCycle = false;
    //    auto slow = head;
    //    auto fast = head;
    //    int maxTry = 0;
    //    while (fast != nullptr && fast->next != nullptr)
    //    {
    //        slow = slow->next;
    //        fast = fast->next->next;
    //        ++maxTry;
    //        if (slow == fast)
    //        {
    //            hasCycle = true;
    //            break;
    //        }
    //    }

    //    if (hasCycle == false)
    //    {
    //        return nullptr;
    //    }

    //    int maxSteps = maxTry * 2;
    //    slow = head;
    //    for (int i = 0; i <= maxTry; ++i)
    //    {
    //        fast = slow;
    //        for (int j = 0; j < maxSteps; ++j)
    //        {
    //            fast = fast->next;
    //            if (slow == fast)
    //            {
    //                return slow;
    //            }
    //        }

    //        slow = slow->next;
    //    }

    //    return nullptr;
    //}
};