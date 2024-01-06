#include "leetcode.h"

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* root = head;
        while (head->next != nullptr) {
            ListNode* nxt = head->next;
            ListNode* mid = new ListNode(gcd(head->val, nxt->val));
            head->next = mid;
            mid->next = nxt;
            head = nxt;
        }

        return root;
    }
};