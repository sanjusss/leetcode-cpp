/*
 * @Author: sanjusss
 * @Date: 2022-04-07 10:05:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-07 10:05:07
 * @FilePath: \0\700\790\796.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        s += s;
        return s.find(goal) != string::npos;
    }
};