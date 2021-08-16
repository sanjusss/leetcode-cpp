/*
 * @Author: sanjusss
 * @Date: 2021-08-16 09:06:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-16 09:08:42
 * @FilePath: \jianzhioffer\22.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k > 0 && fast != nullptr) {
            fast = fast->next;
            --k;
        }

        if (k > 0) {
            return nullptr;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};