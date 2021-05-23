/*
 * @Author: sanjusss
 * @Date: 2021-05-23 10:56:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-23 12:12:24
 * @FilePath: \C\C200\C240\C242\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> sums;
        sums.reserve(stones.size() + 1);
        sums.push_back(0);
        for (int i : stones) {
            sums.push_back(sums.back() + i);
        }

        int ans = sums.back();
        for (int remove = stones.size() - 1; remove >= 2; --remove) { //remove 移除的数量
            int score = sums[remove];//本次得分
            ans = max(ans, score - ans);
        }
        
        return ans;
    }
};