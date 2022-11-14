/*
 * @Author: sanjusss
 * @Date: 2022-11-14 21:40:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-14 22:05:39
 * @FilePath: \0\800\800\805.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int g = gcd(sum, n);
        if (g == 1) {
            return false;
        }

        int stepa = sum / g;
        int stepi = n /g;
        vector<int> target(n / 2 + 1, -1);
        target[0] = 0;
        int half = 0;
        for (int i = stepi; i <= n / 2; i += stepi) {
            target[i] = target[i - stepi] + stepa;
            half = i;
        }

        vector<unordered_set<int>> dp(half + 1);
        dp[0].insert(0);

        for (int i : nums) {
            for (int j = half; j > 0; --j) {
                for (int k : dp[j - 1]) {
                    int v = k + i;
                    if (v == target[j]) {
                        return true;
                    }
                    
                    dp[j].insert(v);
                }
            }
        }

        return false;
    }
};

TEST(&Solution::splitArraySameAverage)