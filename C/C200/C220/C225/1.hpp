/*
 * @Author: sanjusss
 * @Date: 2021-01-24 10:34:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 10:37:44
 * @FilePath: \C\C200\C220\C225\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            if (time[1] == '?' || time[1] <= '3') {
                time[0] = '2';
            }
            else {
                time[0] = '1';
            }
        }

        if (time[1] == '?') {
            if (time[0] == '2') {
                time[1] = '3';
            }
            else {
                time[1] = '9';
            }
        }

        if (time[3] == '?') {
            time[3] = '5';
        }

        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
    }
};