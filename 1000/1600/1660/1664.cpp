/*
 * @Author: sanjusss
 * @Date: 2023-01-28 09:48:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-28 10:07:45
 * @FilePath: \1000\1600\1660\1664.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int waysToMakeFair(vector<int>& nums) {
//         vector<vector<int>> sum(2);
//         sum[0].push_back(0);
//         sum[1].push_back(0);
//         int n = nums.size();
//         int all = 0;
//         for (int i = 0; i < n; ++i) {
//             auto& s = sum[i % 2];
//             s.push_back(s.back() + nums[i]);
//             all += nums[i];
//         }

//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             auto& s1 = sum[i % 2];
//             auto& s2 = sum[1 - (i % 2)];

//             int sub = s1[i / 2] + s2.back() - s2[(i + 1) / 2];
//             if (sub == all - sub - nums[i]) {
//                 ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                diff += nums[i];
            }
            else {
                diff -= nums[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                diff -= nums[i];
            }
            else {
                diff += nums[i];
            }

            if (diff == 0) {
                ++ans;
            }

            if (i % 2 == 0) {
                diff -= nums[i];
            }
            else {
                diff += nums[i];
            }
        }

        return ans;
    }
};

TEST(&Solution::waysToMakeFair)