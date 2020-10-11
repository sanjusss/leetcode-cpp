/*
 * @Author: sanjusss
 * @Date: 2020-10-11 09:18:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-11 10:19:58
 * @FilePath: \0\400\410\test416.cpp
 */
#include "416_20201011.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.canPartition(nums);
    
    testCheckEqual(expected, actual);
}