#include "leetcode.h"

// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         ListNode* begin = head;
//         ListNode* beginPrev = nullptr;
//         for (int i = 1; i < left; ++i) {
//             beginPrev = begin;
//             begin = begin->next;
//         }

//         ListNode* end = begin;
//         for (int i = left; i < right; ++i) {
//             end = end->next;
//         }

//         ListNode* endNext = end->next;
//         ListNode* cur = begin;
//         ListNode* prev = endNext;
//         ListNode* next;
//         while (cur != endNext) {
//             next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }

//         if (beginPrev == nullptr) {
//             head = end;
//         }
//         else {
//             beginPrev->next = end;
//         }

//         return head;
//     }
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* begin = head;
        ListNode* beginPrev = nullptr;
        for (int i = 1; i < left; ++i) {
            beginPrev = begin;
            begin = begin->next;
        }

        ListNode* cur = begin;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for (int i = left; i <= right; ++i) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        begin->next = next;
        if (beginPrev == nullptr) {
            head = prev;
        }
        else {
            beginPrev->next = prev;
        }

        return head;
    }
};

TEST(&Solution::reverseBetween)