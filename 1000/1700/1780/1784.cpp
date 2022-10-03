/*
 * @Author: sanjusss
 * @Date: 2022-10-03 08:45:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-03 08:45:21
 * @FilePath: \1000\1700\1780\1784.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool allowOne = true;
        for (char i : s) {
            if (i == '1') {
                if (!allowOne) {
                    return false;
                }
            }
            else {
                allowOne = false;
            }
        }

        return true;
    }
};