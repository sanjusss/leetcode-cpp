/*
 * @Author: sanjusss
 * @Date: 2021-11-02 08:39:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-02 08:40:16
 * @FilePath: \0\200\230\237_20211102.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};