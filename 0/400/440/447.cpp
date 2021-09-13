/*
 * @Author: sanjusss
 * @Date: 2021-09-13 08:46:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-13 09:19:39
 * @FilePath: \0\400\440\447.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<int, int> cnt;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }

                int x2 = points[j][0];
                int y2 = points[j][1];
                int dis2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                ans += cnt[dis2]++;
            }
        }

        return ans * 2;
    }
};

TEST(&Solution::numberOfBoomerangs)