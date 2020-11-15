/*
 * @Author: sanjusss
 * @Date: 2020-11-15 15:23:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-15 15:26:13
 * @FilePath: \0\400\400\test402.cpp
 */
#include "402.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto num = params[0];
    int k = stoi(params[1]);
    string expected = params[2];

    Solution sln;
    string actual = sln.removeKdigits(num, k);
    AREEQUAL(expected, actual);
}