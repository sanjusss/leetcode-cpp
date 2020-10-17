/*
 * @Author: sanjusss
 * @Date: 2020-10-17 09:52:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-17 09:54:35
 * @FilePath: \0\0\50\test52.cpp
 */
#include "52.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.totalNQueens(n);

    testCheckEqual(expected, actual);
}