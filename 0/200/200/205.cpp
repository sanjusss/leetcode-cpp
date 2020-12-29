/*
 * @Author: sanjusss
 * @Date: 2020-12-27 12:59:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 20:02:24
 * @FilePath: \0\200\200\205.cpp
 */
#include "205_20201227.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    string t = params[1];
    bool expected = stob(params[2]);
    
    Solution sln;
    bool actual = sln.isIsomorphic(s, t);

    AREEQUAL(expected, actual);
}