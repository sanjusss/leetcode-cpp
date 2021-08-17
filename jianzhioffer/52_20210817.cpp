/*
 * @Author: sanjusss
 * @Date: 2021-08-17 08:40:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-17 08:52:38
 * @FilePath: \jianzhioffer\52_20210817.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* a = headA;
//         bool switchA = false;
//         ListNode* b = headB;
//         bool switchB = false;
//         while (a != nullptr && b != nullptr) {
//             if (a == b) {
//                 return a;
//             }

//             if (a->next == nullptr && !switchA) {
//                 a = headB;
//                 switchA = true;
//             }
//             else {
//                 a = a->next;
//             }

//             if (b->next == nullptr && !switchB) {
//                 b = headA;
//                 switchB = true;
//             }
//             else {
//                 b = b->next;
//             }
//         }

//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b) {
            if (a == nullptr) {
                a = headB;
            }
            else {
                a = a->next;
            }

            if (b == nullptr) {
                b = headA;
            }
            else {
                b = b->next;
            }
        }

        return a;
    }
};