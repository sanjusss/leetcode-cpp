/*
 * @Author: sanjusss
 * @Date: 2020-12-30 15:42:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-30 15:46:36
 * @FilePath: \1000\1000\1040\1046.cpp
 */
#include "1046.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto stones = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.lastStoneWeight(stones);

    AREEQUAL(expected, actual);
}