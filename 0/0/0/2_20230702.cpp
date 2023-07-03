/*
 * @Author: sanjusss
 * @Date: 2023-07-02 10:11:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-02 10:17:39
 * @FilePath: \0\0\0\2_20230702.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode* cur = &root;
        int r = 0;
        while (l1 != nullptr || l2 != nullptr || r != 0) {
            cur->next = new ListNode(0);
            cur = cur->next;
            cur->val += r;
            if (l1 != nullptr) {
                cur->val += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                cur->val += l2->val;
                l2 = l2->next;
            }

            r = cur->val / 10;
            cur->val %= 10;
        }

        return root.next;
    }
};