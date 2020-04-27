#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> reversePrint(ListNode* head) 
    {
        vector<int> ans;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};