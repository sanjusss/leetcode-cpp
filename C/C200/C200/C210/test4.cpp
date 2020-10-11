/*
 * @Author: sanjusss
 * @Date: 2020-10-11 11:49:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 11:50:49
 * @FilePath: \C\C200\C200\C210\test4.cpp
 */
#include "4.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    auto edges = toInt2DArray(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.countSubgraphsForEachDiameter(n, edges);

    testCheckEqual(expected, actual);
}