#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        auto temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};