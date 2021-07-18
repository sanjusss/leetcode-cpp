/*
 * @Author: sanjusss
 * @Date: 2021-07-18 10:43:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-18 11:01:19
 * @FilePath: \C\C200\C250\C250\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<int64_t> prev(n);
        vector<int64_t> cur(n);
        for (const auto& pts : points) {
            swap(prev, cur);
            //0到n - 1
            int64_t prevMax = 0;
            for (int i = 0; i < n; ++i) {
                prevMax = max(prevMax, prev[i]);
                cur[i] = pts[i] + prevMax;
                --prevMax;
            }

            prevMax = 0;
            for (int i = n - 1; i >= 0; --i) {
                prevMax = max(prevMax, prev[i]);
                cur[i] = max(cur[i], pts[i] + prevMax);
                --prevMax;
            }
        }

        return *max_element(cur.begin(), cur.end());
    }
};