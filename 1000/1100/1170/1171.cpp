/*
 * @Author: sanjusss
 * @Date: 2023-06-11 12:05:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 12:07:10
 * @FilePath: \1000\1100\1170\1171.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode*> nodes;
        while (head != nullptr) {
            int sum = head->val;
            for (int i = (int)nodes.size() - 1; i >= 0 && sum != 0; --i) {
                sum += nodes[i]->val;
                if (sum == 0) {
                    nodes.resize(i);
                }
            }

            if (sum != 0) {
                nodes.push_back(head);
            }

            head = head->next;
        }

        if (nodes.empty()) {
            return nullptr;
        }

        for (int i = 1; i < nodes.size(); ++i) {
            nodes[i - 1]->next = nodes[i];
        }

        nodes.back()->next = nullptr;
        return nodes.front();
    }
};