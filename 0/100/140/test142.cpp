/*
 * @Author: sanjusss
 * @Date: 2020-10-10 08:06:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-10 08:35:37
 * @FilePath: \0\100\140\test142.cpp
 */
#include "142_20201010.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    vector<ListNode*> nodes;
    auto head = toListNode(params[0], &nodes);
    int pos = stoi(params[1]);
    ListNode* expected = nullptr;
    if (pos >= 0) {
        nodes.back()->next = nodes[pos];
        expected = nodes[pos];
    }

    Solution sln;
    auto actual = sln.detectCycle(head);
    
    testCheckSame(expected, actual);
}