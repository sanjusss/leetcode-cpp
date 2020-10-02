#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    ListNode* reverseKGroup(ListNode* head, int k) 
//    {
//        if (k <= 1)
//        {
//            return head;
//        }
//
//        ListNode* root = nullptr;
//        ListNode* cur = nullptr;
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (slow != nullptr)
//        {
//            for (int i = 1; i < k; ++i)
//            {
//                fast = fast->next;
//                if (fast == nullptr)
//                {
//                    return root == nullptr ? head : root;
//                }
//            }
//
//            reverse(slow, fast);
//            if (root == nullptr)
//            {
//                root = fast;
//                cur = slow;
//            }
//            else
//            {
//                cur->next = fast;
//                cur = slow;
//            }
//
//            fast = slow->next;
//            slow = fast;
//        }
//
//        return root == nullptr ? head : root;
//    }
//
//private:
//    void reverse(ListNode* head, ListNode* tail)
//    {
//        ListNode* prev = tail->next;
//        ListNode* cur = head;
//        ListNode* next;
//        while (prev != tail)
//        {
//            next = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = next;
//        }
//    }
//};

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k <= 1)
        {
            return head;
        }

        ListNode root(0);
        root.next = head;
        ListNode* fast = &root;
        ListNode* slow = &root;
        while (slow->next != nullptr)
        {
            for (int i = 0; i < k; ++i)
            {
                fast = fast->next;
                if (fast == nullptr)
                {
                    return root.next;
                }
            }

            fast = reverseNext(slow, fast);
            slow = fast;
        }

        return root.next;
    }

private:
    //·´×ªhead.nextµ½tail
    ListNode* reverseNext(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next;
        ListNode* cur = head->next;
        ListNode* next;
        while (prev != tail)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode* res = head->next;
        head->next = tail;
        return res;
    }
};