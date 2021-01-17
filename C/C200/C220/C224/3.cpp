/*
 * @Author: sanjusss
 * @Date: 2021-01-17 11:45:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 11:48:12
 * @FilePath: \C\C200\C220\C224\3.cpp
 */
#include "3.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto matrix = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.largestSubmatrix(matrix);
    
    AREEQUAL(expected, actual);
}