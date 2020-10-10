/*
 * @Author: sanjusss
 * @Date: 2020-10-10 08:06:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-10 09:28:06
 * @FilePath: \0\100\140\142_20201010.hpp
 */
#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> nodes;
//         while (head != nullptr) {
//             if (nodes.find(head) == nodes.end()) {
//                 nodes.insert(head);
//                 head = head->next;
//             }
//             else {
//                 return head;
//             }
//         }

//         return nullptr;
//     }
// };

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        
        return nullptr;
    }
};