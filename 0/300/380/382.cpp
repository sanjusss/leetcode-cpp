/*
 * @Author: sanjusss
 * @Date: 2022-01-16 11:27:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-16 11:29:57
 * @FilePath: \0\300\380\382.cpp
 */
#include "leetcode.h"

class Solution {
public:
    Solution(ListNode* head) {
        while (head != nullptr) {
            m_arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return m_arr[rand() % m_arr.size()];
    }

private:
    vector<int> m_arr;
};