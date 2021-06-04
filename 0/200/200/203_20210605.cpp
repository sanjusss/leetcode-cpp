/*
 * @Author: sanjusss
 * @Date: 2021-06-05 06:54:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-05 06:57:20
 * @FilePath: \0\200\200\203_20210605.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode root(0);
        root.next = head;
        ListNode* node = &root;
        while (node->next != nullptr) {
            if (node->next->val == val) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }

        return root.next;
    }
};

TEST(&Solution::removeElements)