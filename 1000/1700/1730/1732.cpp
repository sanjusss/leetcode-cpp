/*
 * @Author: sanjusss
 * @Date: 2022-11-19 11:08:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-19 11:08:36
 * @FilePath: \1000\1700\1730\1732.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int h = 0;
        for (int i : gain) {
            h += i;
            ans = max(ans, h);
        }

        return ans;
    }
};