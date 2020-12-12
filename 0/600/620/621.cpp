/*
 * @Author: sanjusss
 * @Date: 2020-12-05 11:41:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-05 11:43:52
 * @FilePath: \0\600\620\621.cpp
 */
#include "621_20201205.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto tasks = toCharArray(params[0]);
    int n = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.leastInterval(tasks, n);

    AREEQUAL(expected, actual);
}