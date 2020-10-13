/*
 * @Author: sanjusss
 * @Date: 2020-10-13 09:15:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-13 09:30:11
 * @FilePath: \0\0\20\24.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode root(0);
        root.next = head;
        head = &root;
        ListNode* temp;
        while (head->next != nullptr) {
            if (head->next->next == nullptr) {
                break;
            } 

            temp = head->next;
            head->next = temp->next;
            temp->next = head->next->next;
            head->next->next = temp;
            head = temp;
        }
        
        return root.next;
    }
};