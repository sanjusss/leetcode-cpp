/*
 * @Author: sanjusss
 * @Date: 2021-06-08 08:25:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-08 08:59:22
 * @FilePath: \1000\1000\1040\1049.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int maxSum = accumulate(stones.begin(), stones.end(), 0);
//         vector<bool> cur(maxSum * 2 + 1);
//         vector<bool> prev = cur;
//         cur[maxSum] = true;
//         for (int i : stones) {
//             swap(prev, cur);
//             fill(cur.begin(), cur.end(), false);
//             for (int j = i; j <= maxSum + maxSum; ++j) {
//                 cur[j] = prev[j - i]; 
//             }

//             for (int j = maxSum + maxSum - i; j >= 0; --j) {
//                 cur[j] = cur[j] || prev[j + i]; 
//             }
//         }

//         for (int i = 0; i <= maxSum; ++i) {
//             if (cur[i + maxSum]) {
//                 return i;
//             }
//         }

//         return maxSum;
//     }
// };

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int maxSum = accumulate(stones.begin(), stones.end(), 0);
        int maxNeg = maxSum / 2;
        vector<bool> dp(maxNeg + 1);
        dp[0] = true;
        for (int i : stones) {
            for (int j = maxNeg; j >= i; --j) {
                dp[j] = dp[j] || dp[j - i];
            }
        }

        for (int i = maxNeg; i >= 0; --i) {
            if (dp[i]) {
                return maxSum - 2 * i;
            }
        }

        return maxSum;
    }
};

TEST(&Solution::lastStoneWeightII)