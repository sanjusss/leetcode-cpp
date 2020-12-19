/*
 * @Author: sanjusss
 * @Date: 2020-12-19 15:47:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-19 16:33:27
 * @FilePath: \0\0\40\48.cpp
 */
#include "48_20201219.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto matrix = toInt2DArray(params[0]);
    auto expected = toInt2DArray(params[1]);

    Solution sln;
    sln.rotate(matrix);


    AREEQUAL(expected, matrix);
}