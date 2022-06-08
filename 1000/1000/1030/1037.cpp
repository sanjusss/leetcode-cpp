/*
 * @Author: sanjusss
 * @Date: 2022-06-08 08:13:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-08 08:16:23
 * @FilePath: \1000\1000\1030\1037.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][1] - points[1][1]) * (points[1][0] - points[2][0]) -
                   (points[1][1] - points[2][1]) * (points[0][0] - points[1][0]) !=
               0;
    }
};