#pragma once
#include "leetcode.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        ListNode* mid = middleNode(head);
        ListNode* right = reverseList(mid->next);
        bool ans = true;
        ListNode* l1 = head;
        ListNode* l2 = right;
        while (l2 != nullptr) {
            if (l1->val != l2->val) {
                ans = false;
                break;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        mid->next = reverseList(right);
        return ans;
    }

private:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};