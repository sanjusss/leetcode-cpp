/*
 * @Author: sanjusss
 * @Date: 2020-10-18 21:40:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-18 21:50:04
 * @FilePath: \0\0\10\19_20201018.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root(0);
        root.next = head;
        ListNode* fast = head;
        ListNode* slow = &root;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return root.next;
    }
};