/*
 * @Author: sanjusss
 * @Date: 2021-08-04 09:20:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-04 10:28:24
 * @FilePath: \0\600\610\611.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] == 0) {
//                 continue;
//             }

//             for (int j = i + 1; j < n; ++j) {
//                 ans += lower_bound(nums.begin() + j, nums.end(), nums[i] + nums[j]) - (nums.begin() + j) - 1;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = i;
            while (j < n) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }

                ans += max(k - j, 0);
                ++j;
            }
        }

        return ans;
    }
};

TEST(&Solution::triangleNumber)