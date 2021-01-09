/*
 * @Author: sanjusss
 * @Date: 2021-01-09 10:56:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-09 11:21:58
 * @FilePath: \0\100\120\123.cpp
 */
#include "123_20210109.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto prices = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.maxProfit(prices);

    AREEQUAL(expected, actual);
}