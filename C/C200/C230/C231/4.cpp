/*
 * @Author: sanjusss
 * @Date: 2021-03-07 16:30:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-07 16:31:50
 * @FilePath: \C\C200\C230\C231\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> size(k);
        vector<unordered_map<int, int>> cnt(k);
        for (int i = 0; i < n; ++i) {
            ++size[i % k];
            ++cnt[i % k][nums[i]];
        }

        vector<int> dp(1 << 10, INT_MAX / 2);
        vector<int> temp(1 << 10);
        dp[0] = 0;
        for (int i = 0; i < k; ++i) {
            fill(temp.begin(), temp.end(), *min_element(dp.begin(), dp.end()) + size[i]);
            for (int j = 0; j < (1 << 10); ++j) {
                for (auto& [l, c] : cnt[i]) {
                    temp[l ^ j] = min(dp[j] + size[i] - c, temp[l ^ j]);
                }
            }

            swap(dp, temp);
        }

        return dp[0];
    }
};

TEST(&Solution::minChanges)