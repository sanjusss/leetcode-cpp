/*
 * @Author: sanjusss
 * @Date: 2021-07-24 15:13:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-24 15:18:04
 * @FilePath: \1000\1700\1730\1736.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            if (time[1] == '?' || time[1] < '4') {
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

TEST(&Solution::maximumTime)