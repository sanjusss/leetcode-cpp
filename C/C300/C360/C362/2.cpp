/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-10 10:39:17
 * @FilePath: \C\C300\C360\C362\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        
        return max(abs(sx - fx), abs(sy - fy)) <= t;
    }
};