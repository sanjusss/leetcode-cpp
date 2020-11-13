#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddRoot(0);
        ListNode evenRoot(0);
        ListNode* odd = &oddRoot;
        ListNode* even = &evenRoot;
        bool isOdd = true;
        while (head != nullptr) {
            if (isOdd) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;
            }

            isOdd = !isOdd;
            head = head->next;
        }

        odd->next = evenRoot.next;
        even->next = nullptr;
        return oddRoot.next;
    }
};