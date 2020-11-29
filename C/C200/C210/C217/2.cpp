/*
 * @Author: sanjusss
 * @Date: 2020-11-29 11:17:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-29 11:19:12
 * @FilePath: \C\C200\C210\C217\2.cpp
 */
#include "2.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int k = stoi(params[1]);
    auto expected = toIntArray(params[2]);
    Solution sln;
    auto actual = sln.mostCompetitive(nums, k);

    AREEQUAL(expected, actual);
}