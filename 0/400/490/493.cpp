/*
 * @Author: sanjusss
 * @Date: 2020-11-28 14:43:04
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-28 14:51:05
 * @FilePath: \0\400\490\493.cpp
 */
#include "493.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.reversePairs(nums);

    AREEQUAL(expected, actual);
}