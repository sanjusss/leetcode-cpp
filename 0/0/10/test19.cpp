/*
 * @Author: sanjusss
 * @Date: 2020-10-18 21:43:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-18 21:49:44
 * @FilePath: \0\0\10\test19.cpp
 */
#include "19_20201018.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    ListNode* head = toListNode(params[0]);
    int n = stoi(params[1]);
    ListNode* expected = toListNode(params[2]);

    Solution sln;
    auto actual = sln.removeNthFromEnd(head, n);
    testCheckEqual(expected, actual);
}