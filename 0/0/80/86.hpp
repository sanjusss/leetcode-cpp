/*
 * @Author: sanjusss
 * @Date: 2021-01-03 14:31:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-03 14:44:54
 * @FilePath: \0\0\80\86.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode leftRoot(0);
        ListNode* left = &leftRoot;
        ListNode rightRoot(0);
        ListNode* right = &rightRoot;

        while (head != nullptr) {
            if (head->val >= x) {
                right->next = head;
                right = head;
            }
            else {
                left->next = head;
                left = head;
            }

            head = head->next;
        }

        left->next = rightRoot.next;
        right->next = nullptr;
        return leftRoot.next;
    }
};