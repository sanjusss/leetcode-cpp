/*
 * @Author: sanjusss
 * @Date: 2020-10-11 10:57:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 10:59:31
 * @FilePath: \C\C200\C200\C210\test3.cpp
 */
#include "3.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto a = params[0];
    auto b = params[1];
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.checkPalindromeFormation(a, b);

    testCheckEqual(expected, actual);
}