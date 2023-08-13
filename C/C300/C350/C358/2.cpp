/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-13 10:41:13
 * @FilePath: \C\C300\C350\C358\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        int r = 0;
        ListNode* root = head;
        ListNode* pre = nullptr;
        while (head != nullptr || r != 0) {
            if (head == nullptr) {
                pre->next = new ListNode(0);
                head = pre->next;
            }

            int v = head->val * 2 + r;
            head->val = v % 10;
            r = v / 10;
            pre = head;
            head = head->next;
        }

        return reverse(root);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }

        return pre;
    }
};