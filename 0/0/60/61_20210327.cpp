/*
 * @Author: sanjusss
 * @Date: 2021-03-27 08:35:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-27 08:44:51
 * @FilePath: \0\0\60\61_20210327.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }

        int len = 0;
        ListNode* node = head;
        while (node != nullptr) {
            ++len;
            node = node->next;
        }

        k %= len;
        if (k == 0) {
            return head;
        }

        node = head;
        for (int i = len - k; i > 1; --i) {
            node = node->next;
        }

        ListNode* newHead = node->next;
        ListNode* end = node;
        while (node->next != nullptr) {
            node = node->next;
        }

        node->next = head;
        end->next = nullptr;
        return newHead;
    }
};

TEST(&Solution::rotateRight)