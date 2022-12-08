/*
 * @Author: sanjusss
 * @Date: 2022-12-08 08:47:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-08 08:48:53
 * @FilePath: \1000\1800\1810\1812.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int p = (coordinates[0] - 'a') % 2;
        p = (p + coordinates[1] - '1') % 2;
        return p == 1;
    }
};