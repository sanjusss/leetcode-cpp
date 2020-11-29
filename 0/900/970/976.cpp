/*
 * @Author: sanjusss
 * @Date: 2020-11-29 14:21:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 14:23:54
 * @FilePath: \0\900\970\976.cpp
 */
#include "976.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.largestPerimeter(A);

    AREEQUAL(expected, actual);
}