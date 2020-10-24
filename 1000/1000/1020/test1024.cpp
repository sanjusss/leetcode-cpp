/*
 * @Author: sanjusss
 * @Date: 2020-10-24 11:08:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-24 11:09:58
 * @FilePath: \1000\1000\1020\test1024.cpp
 */
#include "1024.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto clips = toInt2DArray(params[0]);
    int T = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.videoStitching(clips, T);

    AREEQUAL(expected, actual);
}