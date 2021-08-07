/*
 * @Author: sanjusss
 * @Date: 2021-08-07 14:59:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-07 15:00:23
 * @FilePath: \jianzhioffer\06.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head != nullptr) {
            ans.push_back(head->val);
            head = head->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};