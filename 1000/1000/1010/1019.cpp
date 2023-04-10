/*
 * @Author: sanjusss
 * @Date: 2023-04-10 09:42:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-10 09:46:00
 * @FilePath: \1000\1000\1010\1019.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, int>> s;
        while (head != nullptr) {
            while (!s.empty() && s.top().first < head->val) {
                ans[s.top().second] = head->val;
                s.pop();
            }

            s.emplace(head->val, ans.size());
            ans.emplace_back(0);
            head = head->next;
        }

        return ans;
    }
};