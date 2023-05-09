/*
 * @Author: sanjusss
 * @Date: 2023-05-09 08:48:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-09 08:54:51
 * @FilePath: \2000\2400\2430\2437.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countTime(string time) {
        int left = 0;
        if (time[0] == '?') {
            if (time[1] == '?') {
                left = 24;
            }
            else if (time[1] > '3') {
                left = 2;
            }
            else {
                left = 3;
            }
        }
        else if (time[0] > '2') {
            return 0;
        }
        else if (time[1] == '?') {
            if (time[0] == '2') {
                left = 4;
            }
            else {
                left = 10;
            }
        }
        else {
            left = 1;
        }

        int right = 0;
        if (time[3] == '?') {
            if (time[4] == '?') {
                right = 60;
            }
            else {
                right = 6;
            }
        }
        else if (time[3] > '5') {
            return 0;
        }
        else if (time[4] == '?') {
            right = 10;
        }
        else {
            right = 1;
        }

        return left * right;
    }
};