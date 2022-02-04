/*
 * @Author: sanjusss
 * @Date: 2022-02-04 09:26:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-04 09:28:17
 * @FilePath: \1000\1700\1720\1725.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int ans = 0;
        for (auto& r : rectangles) {
            int len = min(r[0], r[1]);
            if (len == maxLen) {
                ++ans;
            }
            else if (len > maxLen) {
                maxLen = len;
                ans = 1;
            }
        }

        return ans;
    }
};