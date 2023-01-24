/*
 * @Author: sanjusss
 * @Date: 2023-01-24 08:55:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-24 08:57:35
 * @FilePath: \1000\1800\1820\1828.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            int r = q[2] * q[2];
            int cnt = 0;
            for (auto& p : points) {
                if ((p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) <= r) {
                    ++cnt;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};