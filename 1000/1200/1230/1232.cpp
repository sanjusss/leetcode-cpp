/*
 * @Author: sanjusss
 * @Date: 2021-01-17 13:29:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 13:46:01
 * @FilePath: \1000\1200\1230\1232.cpp
 */
#include "1232.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto coordinates = toInt2DArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.checkStraightLine(coordinates);

    AREEQUAL(expected, actual);
}