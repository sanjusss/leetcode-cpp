/*
 * @Author: sanjusss
 * @Date: 2020-11-07 11:42:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-07 11:45:12
 * @FilePath: \0\300\320\test327.cpp
 */
#include "327.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int lower = stoi(params[1]);
    int upper = stoi(params[2]);
    int expected = stoi(params[3]);

    Solution sln;
    int actual = sln.countRangeSum(nums, lower, upper);

    AREEQUAL(expected, actual);
}