/*
 * @Author: sanjusss
 * @Date: 2021-08-07 15:01:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-07 15:02:49
 * @FilePath: \jianzhioffer\24.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};