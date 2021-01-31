/*
 * @Author: sanjusss
 * @Date: 2021-01-31 10:57:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-31 11:18:57
 * @FilePath: \C\C200\C220\C226\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<int64_t> sums;
        sums.reserve(candiesCount.size() + 1);
        sums.push_back(0);
        for (int i : candiesCount) {
            sums.push_back(i + sums.back());
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int64_t type = q[0];
            int64_t day = q[1];
            int64_t limit = q[2];
            int64_t minEat = day + 1;
            int64_t maxEat = day * limit + limit;
            ans.push_back(sums[type] < maxEat && sums[type + 1] >= minEat);
        }

        return ans;
    }
};

TEST(Solution::canEat)