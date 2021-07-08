/*
 * @Author: sanjusss
 * @Date: 2021-07-08 08:33:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-08 09:20:18
 * @FilePath: \0\900\930\930.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int ans = 0;
//         int n = nums.size();
//         vector<int> cur(n + 1);
//         vector<int> prev(n + 1);
//         for (int i : nums) {
//             swap(prev, cur);
//             fill(cur.begin(), cur.end(), 0);
//             for (int j = i; j <= n; ++j) {
//                 cur[j] = prev[j - i];
//             }

//             ++cur[i];
//             ans += cur[goal];
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int ans = 0;
//         vector<int> dp;
//         dp.reserve(nums.size() + 1);
//         dp.push_back(0);
//         for (int i : nums) {
//             ++dp.back();
//             if (i == 1) {
//                 dp.push_back(0);
//             }

//             if (dp.size() > goal) {
//                 ans += dp[dp.size() - 1 - goal];
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int ans = 0;
//         vector<int> cnt(nums.size() + 1);
//         // unordered_map<int, int> cnt;
//         int sum = 0;
//         for (int i : nums) {
//             ++cnt[sum];
//             sum += i;
//             if (sum >= goal) {
//                 ans += cnt[sum - goal];
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int left1 = 0;
        int left2 = 0;
        int n = nums.size();
        int sum1 = 0;
        int sum2 = 0;
        for (int right = 0; right < n; ++right) {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1++];
            }

            sum2 += nums[right];
            while (left2 <= right && sum2 >= goal) {
                sum2 -= nums[left2++];
            }

            ans += left2 - left1;
        }

        return ans;
    }
};

TEST(&Solution::numSubarraysWithSum)