#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode root(0);
        root.next = head;
        ListNode* i;
        ListNode* j;
        ListNode* prev = &root;
        while (head != nullptr) {
            i = root.next;
            j = &root;
            while (i != head) {
                if (head->val < i->val) {
                    prev->next = head->next;
                    j->next = head;
                    head->next = i;
                    head = prev;
                    break;
                }
                else {
                    j = i;
                    i = i->next;
                }
            }

            prev = head;
            head = head->next;
        }

        return root.next;
    }
};