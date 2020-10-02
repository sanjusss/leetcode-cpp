#pragma once
#include "leetcode.h"

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        stack<int> s2;
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* head = nullptr;
        int v = 0;
        while (s1.empty() == false || s2.empty() == false)
        {
            if (s1.empty() == false)
            {
                v += s1.top();
                s1.pop();
            }

            if (s2.empty() == false)
            {
                v += s2.top();
                s2.pop();
            }

            ListNode* node = new ListNode(v % 10);
            node->next = head;
            head = node;

            v /= 10;
        }

        if (v > 0)
        {
            ListNode* node = new ListNode(v);
            node->next = head;
            head = node;
        }
        else
        {
            if (head == nullptr)
            {
                head = new ListNode(0);
            }
        }

        return head;
    }
};