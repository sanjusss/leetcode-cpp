/*
 * @Author: sanjusss
 * @Date: 2020-12-12 11:45:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-12 11:47:32
 * @FilePath: \0\300\370\376.cpp
 */
#include "376.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums = toIntArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.wiggleMaxLength(nums);

    AREEQUAL(expected, actual);
}