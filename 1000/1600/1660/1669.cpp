/*
 * @Author: sanjusss
 * @Date: 2023-01-30 09:03:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-30 09:07:11
 * @FilePath: \1000\1600\1660\1669.cpp
 */
#include "leetcode.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto ans = list1;
        ListNode* prev = nullptr;
        for (int i = 0; i < a; ++i) {
            prev = list1;
            list1 = list1->next;
        }

        prev->next = list2;
        while (list2->next != nullptr) {
            list2 = list2->next;
        }

        for (int i = a; i <= b; ++i) {
            list1 = list1->next;
        }

        list2->next = list1;
        return ans;
    }
};