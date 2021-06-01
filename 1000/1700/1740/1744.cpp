/*
 * @Author: sanjusss
 * @Date: 2021-06-01 08:59:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-01 09:49:23
 * @FilePath: \1000\1700\1740\1744.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<int64_t> sums;
        sums.reserve(candiesCount.size() + 1);
        sums.push_back(0);
        for (int i : candiesCount) {
            sums.push_back(sums.back() + i);
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int64_t type = q[0];
            int64_t day = q[1] + 1;
            int64_t cap = q[2];
            int64_t maxDay = sums[type + 1];
            int64_t minDay = (sums[type] + cap) / cap;
            ans.push_back(day >= minDay && day <= maxDay);
        }

        return ans;
    }
};

TEST(&Solution::canEat)