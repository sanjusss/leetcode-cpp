/*
 * @Author: sanjusss
 * @Date: 2020-11-22 11:38:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 11:41:58
 * @FilePath: \0\200\240\test242.hpp
 */
#include "242_20201122.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    string t = params[1];
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.isAnagram(s, t);

    AREEQUAL(expected, actual);
}