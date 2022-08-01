/*
 * @Author: sanjusss
 * @Date: 2022-08-01 08:32:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-01 08:45:19
 * @FilePath: \0\300\360\369.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     ListNode* plusOne(ListNode* head) {
//         head = reverse(head);
//         int r = 1;
//         auto node = head;
//         while (node != nullptr) {
//             node->val += r;
//             if (node->val == 10) {
//                 node->val = 0;
//                 r = 1;
//             }
//             else {
//                 r = 0;
//             }

//             node = node->next;
//         }

//         head = reverse(head);
//         if (r > 0) {
//             return new ListNode(r, head);
//         }
//         else {
//             return head;
//         }
//     }

// private:
//     ListNode* reverse(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* cur = head;
//         while (cur != nullptr) {
//             ListNode* next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }

//         return prev;
//     }
// };

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* begin = new ListNode(0, head);
        auto change = begin;
        while (head != nullptr) {
            if (head->val != 9) {
                change = head;
            }

            head = head->next;
        }

        change->val += 1;
        change = change->next;
        while (change != nullptr) {
            change->val = 0;
            change = change->next;
        }

        if (begin->val != 0) {
            return begin;
        }
        else {
            return begin->next;
        }
    }
};