/*
 * @Author: sanjusss
 * @Date: 2020-12-06 11:47:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-06 11:50:51
 * @FilePath: \C\C200\C210\C218\4.cpp
 */
#include "4.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int k = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.minimumIncompatibility(nums, k);

    AREEQUAL(expected, actual);
}