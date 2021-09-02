/*
 * @Author: sanjusss
 * @Date: 2021-09-02 08:17:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-02 08:19:03
 * @FilePath: \jianzhioffer\22_20210902.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        for (int i = 0; i < k && fast != nullptr; ++i, fast = fast->next);
        ListNode* slow = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};