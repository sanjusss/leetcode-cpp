#include "leetcode.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        head = reverse(head);
        ListNode* root = head;
        while (head->next != nullptr) {
            if (head->next->val < head->val) {
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }

        return reverse(root);
    }

private:
    static ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }

        return pre;
    }
};