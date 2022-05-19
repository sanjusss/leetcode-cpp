/*
 * @Author: sanjusss
 * @Date: 2022-05-19 11:14:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-19 11:28:09
 * @FilePath: \0\400\460\462.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int64_t> sums;
//         sums.push_back(0);
//         for (int i : nums) {
//             sums.push_back(sums.back() + i);
//         }

//         int64_t ans = INT_MAX;
//         int64_t n = nums.size();
//         for (int64_t i = 0; i < n; ++i) {
//             int64_t cnt = nums[i] * i - sums[i];
//             cnt += sums[n] - sums[i + 1] - nums[i] * (n - i - 1);
//             ans = min(ans, cnt);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int target = nums[n / 2];
        int ans = 0;
        for (int i : nums) {
            ans += abs(i - target);
        }
        
        return ans;
    }
};

TEST(&Solution::minMoves2)