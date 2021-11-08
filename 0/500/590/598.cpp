/*
 * @Author: sanjusss
 * @Date: 2021-11-07 09:52:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-07 09:55:23
 * @FilePath: \0\500\590\598.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minA = m;
        int minB = n;
        for (auto &op : ops) {
            minA = min(minA, op[0]);
            minB = min(minB, op[1]);
        }

        return minA * minB;
    }
};