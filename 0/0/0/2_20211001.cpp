/*
 * @Author: sanjusss
 * @Date: 2021-10-01 13:08:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-01 13:21:29
 * @FilePath: \0\0\0\2_20211001.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int r = 0;
//         ListNode* cur = nullptr;
//         while (l1 != nullptr || l2 != nullptr || r != 0) {
//             if (l1 != nullptr) {
//                 r += l1->val;
//                 l1 = l1->next;
//             }

//             if (l2 != nullptr) {
//                 r += l2->val;
//                 l2 = l2->next;
//             }

//             ListNode* next = new ListNode(r % 10);
//             next->next = cur;
//             cur = next;
//             r /= 10;
//         }

//         ListNode* prev = nullptr;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = 0;
        ListNode* cur = nullptr;
        ListNode* ans = nullptr;
        while (l1 != nullptr || l2 != nullptr || r != 0) {
            if (l1 != nullptr) {
                r += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                r += l2->val;
                l2 = l2->next;
            }

            ListNode* next = new ListNode(r % 10);
            if (cur == nullptr) {
                cur = next;
                ans = next;
            }
            else {
                cur->next = next;
                cur = next;
            }
            
            r /= 10;
        }
        
        return ans;
    }
};

TEST(&Solution::addTwoNumbers)