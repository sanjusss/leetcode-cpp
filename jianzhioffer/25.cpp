/*
 * @Author: sanjusss
 * @Date: 2021-08-17 08:36:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-17 08:39:19
 * @FilePath: \jianzhioffer\25.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode* head = &root;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else {
                head->next = l2;
                l2 = l2->next;
            }

            head = head->next;
        }

        if (l1 != nullptr) {
            head->next = l1;
        }
        else {
            head->next = l2;
        }

        return root.next;
    }
};