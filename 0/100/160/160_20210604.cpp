/*
 * @Author: sanjusss
 * @Date: 2021-06-04 08:18:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-04 08:38:31
 * @FilePath: \0\100\160\160_20210604.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if (headA == nullptr || headB == nullptr) {
//             return nullptr;
//         }

//         int lenA = 0;
//         ListNode *nodeA = headA;
//         while (nodeA->next != nullptr) {
//             ++lenA;
//             nodeA = nodeA->next;
//         }

//         int lenB = 0;
//         ListNode *nodeB = headB;
//         while (nodeB->next != nullptr) {
//             ++lenB;
//             nodeB = nodeB->next;
//         }

//         if (nodeA != nodeB) {
//             return nullptr;
//         }

//         int dis = abs(lenA - lenB);
//         int length = min(lenA, lenB);
//         ListNode* fast = lenA > lenB ? headA : headB;
//         ListNode* slow = lenA > lenB ? headB : headA;
//         while (dis > 0) {
//             fast = fast->next;
//             --dis;
//         }

//         while (fast != slow) {
//             fast = fast->next;
//             slow = slow->next;
//         }

//         return fast;
//     }
// };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        auto a = headA;
        auto b = headB;
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};