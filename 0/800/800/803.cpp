/*
 * @Author: sanjusss
 * @Date: 2021-01-16 21:35:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-16 21:37:48
 * @FilePath: \0\800\800\803.cpp
 */
#include "803.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto grid = toInt2DArray(params[0]);
    auto hits = toInt2DArray(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.hitBricks(grid, hits);

    AREEQUAL(expected, actual);
}