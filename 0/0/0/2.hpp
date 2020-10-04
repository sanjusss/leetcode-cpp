#pragma once
#include "leetcode.h"

// class Solution 
// {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//     {
//         shared_ptr<ListNode> root(new ListNode(0));
//         ListNode* head = root.get();
//         ListNode* cur = nullptr;
//         int re = 0;
//         while (l1 != nullptr || l2 != nullptr)
//         {
//             cur = new ListNode(re);

//             if (l1 != nullptr)
//             {
//                 cur->val += l1->val;
//                 l1 = l1->next;
//             }

//             if (l2 != nullptr)
//             {
//                 cur->val += l2->val;
//                 l2 = l2->next;
//             }

//             if (cur->val >= 10)
//             {
//                 cur->val -= 10;
//                 re = 1;
//             }
//             else
//             {
//                 re = 0;
//             }

//             head->next = cur;
//             head = cur;
//         }

//         if (re != 0)
//         {
//             head->next = new ListNode(re);
//         }

//         return root->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode* head = &root;
        int remain = 0;
        while (l1 != nullptr && l2 != nullptr) {
            head->next = new ListNode(remain);
            head = head->next;
            head->val += l1->val + l2->val;
            if (head->val >= 10) {
                remain = 1;
                head->val -= 10;
            }
            else {
                remain = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            head->next = new ListNode(remain + l1->val);
            head = head->next;
            if (head->val >= 10) {
                remain = 1;
                head->val -= 10;
            }
            else {
                remain = 0;
            }
            
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            head->next = new ListNode(remain + l2->val);
            head = head->next;
            if (head->val >= 10) {
                remain = 1;
                head->val -= 10;
            }
            else {
                remain = 0;
            }
            
            l2 = l2->next;
        }

        if (remain != 0) {
            head->next = new ListNode(remain);
        }

        return root.next;
    }
};