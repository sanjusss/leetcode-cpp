/*
 * @Author: sanjusss
 * @Date: 2021-01-24 10:47:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 10:48:24
 * @FilePath: \C\C200\C220\C225\2.cpp
 */
#include "2.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string a = params[0];
    string b = params[1];
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.minCharacters(a, b);

    AREEQUAL(expected, actual);
}