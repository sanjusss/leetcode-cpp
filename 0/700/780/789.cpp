/*
 * @Author: sanjusss
 * @Date: 2021-08-22 09:21:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 09:24:55
 * @FilePath: \0\700\780\789.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis = abs(target[0]) + abs(target[1]);
        for (auto& g : ghosts) {
            if (abs(g[0] - target[0]) + abs(g[1] - target[1]) <= dis) {
                return false;
            } 
        }

        return true;
    }
};

TEST(&Solution::escapeGhosts)