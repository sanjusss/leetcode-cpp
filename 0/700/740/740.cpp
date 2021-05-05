/*
 * @Author: sanjusss
 * @Date: 2021-05-05 20:49:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-05 21:00:10
 * @FilePath: \0\700\740\740.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> cnt;
        for (int i : nums) {
            ++cnt[i];
        }

        int prev2earn = 0;
        int prev1earn = 0;
        int prev1 = INT_MIN;
        for (auto& [i, c] : cnt) {
            if (i - 1 == prev1) {
                tie(prev1earn, prev2earn) = make_pair(i * c + prev2earn, max(prev1earn, prev2earn));
            }
            else {
                prev2earn = max(prev1earn, prev2earn);
                prev1earn = prev2earn + i * c;
            }

            prev1 = i;
        }

        return max(prev1earn, prev2earn);
    }
};

TEST(&Solution::deleteAndEarn)