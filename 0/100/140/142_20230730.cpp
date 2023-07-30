#include "leetcode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head;
        auto fast = head;
        while (fast) {
            fast = fast->next;
            if (fast == nullptr) {
                return nullptr;
            }

            fast = fast->next;
            slow = slow->next;
            if (fast != slow) {
                continue;
            }

            auto t = head;
            while (t != slow) {
                t = t->next;
                slow = slow->next;
            }

            return t;
        }

        return nullptr;
    }
};