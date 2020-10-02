#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) 
//    {
//        auto cmp = [](ListNode* a, ListNode* b)
//        {
//            return a->val > b->val;
//        };
//        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> nodes(cmp);
//        for (auto node : lists)
//        {
//            if (node != nullptr)
//            {
//                nodes.push(node);
//            }
//        }
//
//        ListNode root(0);
//        ListNode* head = &root;
//        while (nodes.empty() == false)
//        {
//            auto node = nodes.top();
//            nodes.pop();
//            head->next = node;
//            head = node;
//            if (node->next != nullptr)
//            {
//                nodes.push(node->next);
//            }
//        }
//
//        return root.next;
//    }
//};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
        {
            return lists[left];
        }

        if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;
        return mergeKLists(mergeKLists(lists, left, mid), mergeKLists(lists, mid + 1, right));
    }

    ListNode* mergeKLists(ListNode* a, ListNode* b)
    {
        if (a == nullptr)
        {
            return b;
        }

        if (b == nullptr)
        {
            return a;
        }

        ListNode root(0);
        ListNode* head = &root;
        do
        {
            if (a->val < b->val)
            {
                head->next = a;
                a = a->next;
            }
            else
            {
                head->next = b;
                b = b->next;
            }

            head = head->next;
        } while (a != nullptr && b != nullptr);

        if (a != nullptr)
        {
            head->next = a;
        }
        else
        {
            head->next = b;
        }

        return root.next;
    }
};