/*
 * @Author: sanjusss
 * @Date: 2020-11-21 15:17:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-21 16:05:13
 * @FilePath: \0\100\140\test148.cpp
 */
#include "148.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    auto expected = toListNode(params[1]);

    Solution sln;
    auto actual = sln.sortList(head);

    AREEQUAL(expected, actual);
}