/*
 * @Author: sanjusss
 * @Date: 2024-01-08 09:42:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-01-08 09:42:20
 * @FilePath: \0\400\440\447_20240108.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            auto& a = points[i];
            unordered_map<int, int> cnt;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                auto& b = points[j];
                cnt[(a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])] += 1;
            }

            for (auto [_, c] : cnt) {
                ans += c * (c - 1);
            }
        }

        return ans;
    }
};

TEST(&Solution::numberOfBoomerangs)