#include "leetcode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode root(0);
        ListNode* cur = &root;
        int r = 0;
        while (l1 != nullptr || l2 != nullptr || r != 0) {
            cur->next = new ListNode(0);
            cur = cur->next;
    
            if (l1 != nullptr) {
                cur->val += l1->val;
                l1 = l1->next;
            }
    
            if (l2 != nullptr) {
                cur->val += l2->val;
                l2 = l2->next;
            }

            cur->val += r;
            r = cur->val / 10;
            cur->val %= 10;
        }

        return reverse(root.next);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        return pre;
    }
};