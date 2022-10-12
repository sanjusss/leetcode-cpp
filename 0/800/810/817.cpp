/*
 * @Author: sanjusss
 * @Date: 2022-10-12 08:23:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-12 08:28:54
 * @FilePath: \0\800\810\817.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> has(nums.begin(), nums.end());
        for (int i : nums) {
            has.insert(i);
        }

        int ans = nums.size();
        while (head->next != nullptr) {
            if (has.count(head->val) && has.count(head->next->val)) {
                --ans;
            }

            head = head->next;
        }

        return ans;
    }
};