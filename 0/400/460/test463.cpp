/*
 * @Author: sanjusss
 * @Date: 2020-10-30 21:34:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-30 21:38:02
 * @FilePath: \0\400\460\test463.cpp
 */
#include "463.hpp"
#include "unittest.h"

DEFINE_TESTS (params, index) {
    auto grid = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.islandPerimeter(grid);

    AREEQUAL(expected, actual);
}