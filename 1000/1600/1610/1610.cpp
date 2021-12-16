/*
 * @Author: sanjusss
 * @Date: 2021-12-16 09:11:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-16 09:32:57
 * @FilePath: \1000\1600\1610\1610.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> rs;
        int sames = 0;
        for (auto& p : points) {
            if (location[0] == p[0] && location[1] == p[1]) {
                ++sames;
            }
            else {
                rs.push_back(atan2((double)(p[1] - location[1]), (double)(p[0] - location[0])));
            }
        }

        sort(rs.begin(), rs.end());
        int n = rs.size();
        for (int i = 0; i < n; ++i) {
            rs.push_back(rs[i] + 2 * M_PI);
        }

        double maxr = angle * M_PI / 180;
        int ans = 0;
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < 2 * n && rs[right] - rs[left] <= maxr) {
                ++right;
            }

            ans = max(ans, right - left);
        }

        return ans + sames;
    }
};