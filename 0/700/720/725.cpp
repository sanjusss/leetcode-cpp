/*
 * @Author: sanjusss
 * @Date: 2021-09-22 07:41:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-22 08:02:38
 * @FilePath: \0\700\720\725.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node = head;
        int len = 0;
        while (node != nullptr) {
            ++len;
            node = node->next;
        }

        int base = len / k;
        int remain = len % k;
        ListNode root(0);
        root.next = head;
        node = &root;
        vector<ListNode*> ans(k, nullptr);
        for (int i = 0; i < k && node->next != nullptr; ++i) {
            ans[i] = node->next;
            for (int j = 0; j < base; ++j) {
                node = node->next;
            }

            if (i < remain) {
                node = node->next;
            }
            
            root.next = node->next;
            node->next = nullptr;
            node = &root;
        }

        return ans;
    }
};