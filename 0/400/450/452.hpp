#pragma once
#include "leetcode.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 1;
        int right = points[0][1];
        for (auto& p : points) {
            if (p[0] > right) {
                ++ans;
                right = p[1];
            }
        }

        return ans;
    }
};