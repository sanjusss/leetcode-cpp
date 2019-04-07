#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        auto fast = head;
        auto slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto right = reverse(slow);
        auto left = head;
        while (right != nullptr)
        {
            if (left->val != right->val)
            {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }

private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};