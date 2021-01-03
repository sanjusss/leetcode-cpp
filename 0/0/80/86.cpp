/*
 * @Author: sanjusss
 * @Date: 2021-01-03 14:32:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-03 14:46:09
 * @FilePath: \0\0\80\86.cpp
 */
#include "86.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    int x = stoi(params[1]);
    auto expected = toListNode(params[2]);

    Solution sln;
    auto actual = sln.partition(head, x);

    AREEQUAL(expected, actual);
}