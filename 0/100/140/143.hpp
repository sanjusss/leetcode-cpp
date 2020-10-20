#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head == nullptr) {
//             return;
//         }
        
//         ListNode* mid = middleNode(head);
//         ListNode* l1 = head;
//         ListNode* l2 = reverseNodes(mid->next);
//         mid->next = nullptr;
//         mergeNodes(l1, l2);
//     }

// private:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* fast = head;
//         ListNode* slow = head;
//         while (fast != nullptr) {
//             if (fast->next == nullptr) {
//                 break;
//             }

//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         return slow;
//     }

//     ListNode* reverseNodes(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         ListNode* prev = head;
//         ListNode* cur = head->next;
//         prev->next = nullptr;
//         ListNode* temp;
//         while (cur != nullptr) {
//             temp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = temp;
//         }

//         return prev;
//     }

//     void mergeNodes(ListNode* l1, ListNode* l2) {
//         ListNode* temp;
//         while (l2 != nullptr) {
//             temp = l1->next;
//             l1->next = l2;
//             l2 = l2->next;
//             l1->next->next = temp;
//             l1 = temp;
//         }
//     }
// };

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (head == nullptr) {
//             return;
//         }
        
//         ListNode* mid = middleNode(head);
//         ListNode* l1 = head;
//         ListNode* l2 = reverseNodes(mid->next);
//         mid->next = nullptr;
//         mergeNodes(l1, l2);
//     }

// private:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* fast = head;
//         ListNode* slow = head;
//         while (fast != nullptr) {
//             if (fast->next == nullptr) {
//                 break;
//             }

//             fast = fast->next->next;
//             slow = slow->next;
//         }

//         return slow;
//     }

//     ListNode* reverseNodes(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         ListNode* prev = head;
//         ListNode* cur = head->next;
//         prev->next = nullptr;
//         ListNode* temp;
//         while (cur != nullptr) {
//             temp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = temp;
//         }

//         return prev;
//     }

//     void mergeNodes(ListNode* l1, ListNode* l2) {
//         ListNode* temp;
//         while (l2 != nullptr) {
//             temp = l1->next;
//             l1->next = l2;
//             l2 = l2->next;
//             l1->next->next = temp;
//             l1 = temp;
//         }
//     }
// };

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = reverseNodes(mid->next);
        mid->next = nullptr;
        mergeNodes(l1, l2);
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

    ListNode* reverseNodes(ListNode* head) {
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

    void mergeNodes(ListNode* l1, ListNode* l2) {
        ListNode* l1temp;
        ListNode* l2temp;
        while (l1 != nullptr && l2 != nullptr) {
            l1temp = l1->next;
            l2temp = l2->next;
            l1->next = l2;
            l2->next = l1temp;
            l1 = l1temp;
            l2 = l2temp;
        }
    }
};