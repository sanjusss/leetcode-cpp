/*
 * @Author: sanjusss
 * @Date: 2020-12-29 20:57:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-30 16:57:33
 * @FilePath: \0\100\180\188.cpp
 */
#include "188_20201229.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int k = stoi(params[0]);
    auto prices = toIntArray(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.maxProfit(k, prices);

    AREEQUAL(expected, actual); 
}