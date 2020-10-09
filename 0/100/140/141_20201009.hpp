/*
 * @Author: sanjusss
 * @Date: 2020-10-09 07:49:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-09 08:03:37
 * @FilePath: \0\100\140\141_20201009.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast != nullptr) {
            if (fast->next == nullptr) {
                break;
            }

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};