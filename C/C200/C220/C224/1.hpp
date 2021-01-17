/*
 * @Author: sanjusss
 * @Date: 2021-01-17 10:30:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 10:33:06
 * @FilePath: \C\C200\C220\C224\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) {
            return 0;
        }

        map<int, int> cnt;
        for (auto& r : rectangles) {
            ++cnt[min(r[0], r[1])];
        }

        return cnt.rbegin()->second;
    }
};