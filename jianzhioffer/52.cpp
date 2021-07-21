/*
 * @Author: sanjusss
 * @Date: 2021-07-21 08:19:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-21 08:23:40
 * @FilePath: \jianzhioffer\52.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            if (pA == nullptr) {
                pA = headB;
            }
            else {
                pA = pA->next;
            }

            if (pB == nullptr) {
                pB = headA;
            }
            else {
                pB = pB->next;
            }
        }

        return pA;
    }
};