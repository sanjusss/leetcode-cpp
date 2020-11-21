/*
 * @Author: sanjusss
 * @Date: 2020-11-21 15:17:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-21 16:15:27
 * @FilePath: \0\100\140\148.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode root(0);
        root.next = head;
        int length = 0;
        while (head != nullptr) {
            ++length;
            head = head->next;
        }

        for (int step = 1; step < length; step *= 2) {
            head = root.next;
            ListNode* prev = &root;
            ListNode* a = nullptr;
            while (head != nullptr) {
                ListNode* node = head;
                for (int i = 1; i < step && head != nullptr; ++i) {
                    head = head->next;
                }

                if (head != nullptr) {
                    ListNode* temp = head->next;
                    head->next = nullptr;
                    head = temp;
                }

                if (a == nullptr) {
                    a = node;
                }
                else {
                    ListNode* temp = mergeList(a, node);
                    a = nullptr;
                    prev->next = temp;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }

                    prev = temp;
                }
            }

            if (a != nullptr) {
                prev->next = a;
            }
        }
        
        return root.next;
    }

private:
    ListNode* mergeList(ListNode* a, ListNode* b) {
        ListNode root(0);
        ListNode* head = &root;
        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                head->next = a;
                a = a->next;
            }
            else {
                head->next = b;
                b = b->next;
            }

            head = head->next;
        }

        if (a == nullptr) {
            head->next = b;
        }
        else {
            head->next = a;
        }

        return root.next;
    }
};