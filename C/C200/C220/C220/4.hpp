/*
 * @Author: sanjusss
 * @Date: 2020-12-20 11:29:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 11:38:41
 * @FilePath: \C\C200\C220\C220\4.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        unordered_map<int, unordered_map<int, int>> dis;
        for (auto& edge : edgeList) {
            dis[edge[0]][edge[1]] = (dis[edge[0]][edge[1]] == 0) ? edge[2] : min(dis[edge[0]][edge[1]], edge[2]);
            dis[edge[1]][edge[0]] = dis[edge[0]][edge[1]];
        }

        vector<bool> ans;
        for (auto& q : queries) {
            
        }

        return ans;
    }
};