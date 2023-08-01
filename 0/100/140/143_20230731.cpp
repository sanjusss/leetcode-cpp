/*
 * @Author: sanjusss
 * @Date: 2023-07-31 09:30:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-31 10:02:06
 * @FilePath: \0\100\140\143_20230731.cpp
 */
#include "leetcode.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode root(0);
        root.next = head;
        ListNode* slow = &root;
        ListNode* fast = &root;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }

        if (slow == nullptr) {
            return;
        }

        ListNode* half = reverse(slow->next);
        slow->next = nullptr;
        while (head != nullptr && half != nullptr) {
            auto nhead = head->next;
            auto nhalf = half->next;
            head->next = half;
            half->next = nhead;
            head = nhead;
            half = nhalf;
        }
    }

private:
    ListNode* reverse(ListNode* node) {
        ListNode* pre = nullptr;
        while (node != nullptr) {
            ListNode* nxt = node->next;
            node->next = pre;
            pre = node;
            node = nxt;
        }

        return pre;
    }
};