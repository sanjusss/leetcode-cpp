/*
 * @Author: sanjusss
 * @Date: 2020-12-05 11:01:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 12:02:39
 * @FilePath: \0\300\310\316.cpp
 */
#include "316_20201220.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    string expected = params[1];

    Solution sln;
    string actual = sln.removeDuplicateLetters(s);

    AREEQUAL(expected, actual);
}