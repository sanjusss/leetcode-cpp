/*
 * @Author: sanjusss
 * @Date: 2022-11-14 21:40:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-16 09:37:31
 * @FilePath: \0\800\800\805.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool splitArraySameAverage(vector<int>& nums) {
//         int n = nums.size();
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int g = gcd(sum, n);
//         if (g == 1) {
//             return false;
//         }

//         int stepa = sum / g;
//         int stepi = n /g;
//         vector<int> target(n / 2 + 1, -1);
//         target[0] = 0;
//         int half = 0;
//         for (int i = stepi; i <= n / 2; i += stepi) {
//             target[i] = target[i - stepi] + stepa;
//             half = i;
//         }

//         vector<unordered_set<int>> dp(half + 1);
//         dp[0].insert(0);

//         for (int i : nums) {
//             for (int j = half; j > 0; --j) {
//                 for (int k : dp[j - 1]) {
//                     int v = k + i;
//                     if (v == target[j]) {
//                         return true;
//                     }
                    
//                     dp[j].insert(v);
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return false;
        }

        int half = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int& i : nums) {
            i *= n;
            i -= sum;
        }

        int halfTotal = accumulate(nums.begin(), nums.begin() + half, 0);
        unordered_set<int> targets;
        for (int mask = (1 << half) - 2;  mask > 0; --mask) {
            int v = 0;
            for (int i = 0; i < half; ++i) {
                if (mask & (1 << i)) {
                    v += nums[i];
                }
            }

            targets.insert(-v);
        }

        if (targets.count(0) || halfTotal == 0) {
            return true;
        }
        else {
            targets.insert(0);
        }

        int rtotal = accumulate(nums.begin() + half, nums.end(), 0);
        if (targets.count(rtotal)) {
            return true;
        }
        else {
            targets.insert(-halfTotal);
        }

        int r = n - half;
        for (int mask = (1 << r) - 2; mask > 0; --mask) {
            int v = 0;
            for (int i = 0; i < r; ++i) {
                if (mask & (1 << i)) {
                    v += nums[half + i];
                }
            }

            if (targets.count(v)) {
                return true;
            }
        }

        return false;
    }
};

TEST(&Solution::splitArraySameAverage)