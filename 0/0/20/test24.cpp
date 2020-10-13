/*
 * @Author: sanjusss
 * @Date: 2020-10-13 09:15:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-13 09:20:07
 * @FilePath: \0\0\20\test24.cpp
 */
#include "24.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    auto expected = toListNode(params[1]);

    Solution sln;
    auto actual = sln.swapPairs(head);

    testCheckEqual(expected, actual);
}