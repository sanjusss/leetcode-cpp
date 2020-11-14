/*
 * @Author: sanjusss
 * @Date: 2020-11-14 16:57:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-14 17:01:51
 * @FilePath: \1000\1100\1120\test1122.cpp
 */
#include "1122.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto arr1 = toIntArray(params[0]);
    auto arr2 = toIntArray(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.relativeSortArray(arr1, arr2);

    AREEQUAL(expected, actual);
}