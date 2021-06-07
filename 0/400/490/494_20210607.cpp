/*
 * @Author: sanjusss
 * @Date: 2021-06-07 08:33:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-07 09:01:27
 * @FilePath: \0\400\490\494_20210607.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int maxSum = accumulate(nums.begin(), nums.end(), 0);
//         if (S > maxSum || S < -maxSum) {
//             return 0;
//         }

//         vector<int> cur(maxSum * 2 + 1);
//         vector<int> prev(maxSum * 2 + 1);
//         cur[maxSum] = 1;
//         for (int i : nums) {
//             swap(cur, prev);
//             fill(cur.begin(), cur.end(), 0);
//             for (int j = -maxSum + i; j <= maxSum; ++j) {
//                 cur[j - i + maxSum] += prev[j + maxSum];
//             }

//             for (int j = maxSum - i; j >= -maxSum; --j) {
//                 cur[j + i + maxSum] += prev[j + maxSum];
//             }
//         }

//         return cur[S + maxSum];
//     }
// };

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - S;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }

        int neg = diff / 2;
        vector<int> cur(neg + 1);
        vector<int> prev(neg + 1);
        cur[0] = 1;
        for (int i : nums) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j <= neg; ++j) {
                if (i > j) {
                    cur[j] = prev[j];
                }
                else {
                    cur[j] = prev[j] + prev[j - i];
                }
            }
        }

        return cur[neg];
    }
};


TEST(&Solution::findTargetSumWays)