/*
 * @Author: sanjusss
 * @Date: 2022-04-09 10:26:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-09 10:48:29
 * @FilePath: \0\700\780\780.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx != ty && sx < tx && sy < ty) {
            if (tx > ty) {
                tx -= ty;
            }
            else {
                ty -= tx;
            }
        }

        if (sx == tx && sy < ty) {
            return sy % sx == ty % sx;
        }
        
        if (sy == ty && sx < tx) {
            return sx % sy == tx % ty;
        }

        return sx == tx && sy == ty;
    }
};

TEST(&Solution::reachingPoints)