/*
 * @Author: sanjusss
 * @Date: 2021-09-12 10:32:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-12 10:36:31
 * @FilePath: \C\C200\C250\C258\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int64_t ans = 0;
        unordered_map<int64_t, int64_t> cnt;
        for (auto& r : rectangles) {
            int64_t w = r[0];
            int64_t h = r[1];
            int64_t g = gcd(w, h);
            w /= g;
            h /= g;
            ans += cnt[(w << 32) | h]++;
        }

        return ans;
    }
};