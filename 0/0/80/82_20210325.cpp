#include "leetcode.h"

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         ListNode root(0);
//         root.next = head;
//         ListNode* prev = &root;
//         ListNode* begin = head;
//         ListNode* end;
//         while (begin != nullptr) {
//             end = begin->next;
//             while (end != nullptr && end->val == begin->val) {
//                 end = end->next;
//             }

//             if (begin->next == end) {
//                 prev = begin;
//                 begin = end;
//             }
//             else {
//                 prev->next = end;
//                 begin = end;
//             }
//         }

//         return root.next;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode root(0, head);
        ListNode* cur = &root;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int v = cur->next->val;
                do {
                    cur->next = cur->next->next;
                } while (cur->next != nullptr && cur->next->val == v);
            }
            else {
                cur = cur->next;
            }
        }

        return root.next;
    }
};

TEST(&Solution::deleteDuplicates)