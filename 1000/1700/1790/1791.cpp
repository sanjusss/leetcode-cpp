/*
 * @Author: sanjusss
 * @Date: 2022-02-18 08:29:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-18 08:31:32
 * @FilePath: \1000\1700\1790\1791.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        else {
            return edges[0][1];
        }
    }
};