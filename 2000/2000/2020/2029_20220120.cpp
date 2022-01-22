/*
 * @Author: sanjusss
 * @Date: 2022-01-20 08:20:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-20 10:28:25
 * @FilePath: \2000\2000\2020\2029_20220120.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3);
        for (int i : stones) {
            ++cnt[i % 3];
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        }
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};

TEST(&Solution::stoneGameIX)