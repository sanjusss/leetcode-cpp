#include "leetcode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while (node != nullptr && node->next != nullptr) {
            if (node->val == node->next->val) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }

        return head;
    }
};

TEST(&Solution::deleteDuplicates)