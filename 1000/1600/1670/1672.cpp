/*
 * @Author: sanjusss
 * @Date: 2022-04-14 08:37:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-14 08:38:02
 * @FilePath: \1000\1600\1670\1672.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for (auto& a : accounts) {
            ans = max(ans, accumulate(a.begin(), a.end(), 0));
        }

        return ans;
    }
};