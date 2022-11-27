/*
 * @Author: sanjusss
 * @Date: 2022-11-27 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-27 10:43:41
 * @FilePath: \C\C300\C320\C321\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode root(INT_MAX);
        root.next = head;
        stack<ListNode*> s;
        s.push(&root);
        while (head != nullptr) {
            while (!s.empty() && s.top()->val < head->val) {
                s.pop();
            }

            s.top()->next = head;
            s.push(head);
            head = head->next;
        }

        return root.next;
    }
};