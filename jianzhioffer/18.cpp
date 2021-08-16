/*
 * @Author: sanjusss
 * @Date: 2021-08-16 09:02:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-16 09:05:23
 * @FilePath: \jianzhioffer\18.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode root(0);
        root.next = head;
        ListNode* prev = &root;
        while (head != nullptr) {
            if (head->val == val) {
                prev->next = head->next;
                break;
            }
            else {
                prev = head;
                head = head->next;
            }
        }

        return root.next;
    }
};